/*
Seifalla Moustafa
cs315 
Homwework 3

question 2 [a]

Program Description: 

This program implements the multiplying 
algorithm. It uses a text file to read
the test values.There are two test values.
It will take these two numbers and display
their product. This program works with 
integers of any length.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//functions prototypes

vector<int> read_file(ifstream &file, int inputs);
vector<int> add(vector<int> x, vector<int> y);
vector<int> multiply(vector<int> x, vector<int> y);

int main(int argc,char *argv[]){

  vector<int> x, y, a;//x and y are the inputs and a is the product

  int numberOfInputs = 0, size;//the first variable is used to 
//count the number of inputs the program has read from the file.
//the second variable is used to store the size of the vectors.

  ifstream fin;//input file object is defined to deal with the file 

  fin.open(argv[1]);//the file was passed to the program as
//a command line argument and the open member function 
//opens it.

  y = read_file(fin, numberOfInputs);//this function reads
//and stores the values in a vector.

  numberOfInputs ++;//we have read one input

  fin.open(argv[1]);//open the file to read the second number

  x = read_file(fin, numberOfInputs);
  
  a = multiply(x, y);//this function multiplies the numbers
//and returns the product

//the following instructions are used to display 
//every element in the vector the represents the
//product.

  size = a.size();

  for(int i = size - 1; i >= 0; i --)

    cout << a[i];

  cout<<endl;

  return 0;

}

//this function takes a file object as a parameter 
//and store the numbers in the file in a vector
//and returns that vector.
vector<int> read_file(ifstream &file, int inputs){

                vector<int> g(0);//vector to store the number

                char my_character = '0';//to store the 
//values read from the text file which are characters

                int n = 0;//to store the numbers only

//the following instructions will read the file as follows:
//if the first number has been read, read the second, and
//stop as soon as the file ends.

                while (file){

                    if(inputs > 0){

                        while(file && my_character != ' ')

                                file.get(my_character);

                        inputs --;

                    }

                    file.get(my_character);

		    if(my_character == ' ' || my_character == '\n')

                        break;
//this intruction avoids storing spaces or new line characters

                    if (my_character != ' ' || my_character != '\n'){

                        n = my_character - '0';

                        g.push_back(n);
                    }
                  
                }
//we close the file after we're done

                file.close();

                return g;

}

//this funtion adds two vectors
vector<int> add(vector<int> x, vector<int> y){
    
 vector<int> a;//vector to store the result
 int c = 0, size, sum;//the first variable 
//is the carry, the third stores the 
//sum of each two digits
    
 while(y.size() < x.size())//adds zeros if y has 
//fewer number of digits
    y.push_back(0);

  size = x.size();

//the following intructions add each two 
//digits and stores the carry
  for(int i = 0; i <= size - 1; i ++){

      sum = x[i] + y[i] + c;

      if(sum == 3){

          c = 1;
          sum = 1;
      }
      else if(sum == 2){

                c = 1;
                sum = 0;
           }
           else
                c = 0;

      a.push_back(sum);

      if(i == size - 1 && c == 1)

      	   a.push_back(c);
  }  
  
  return a;
}

//this function multiplies two vectors
vector<int> multiply(vector<int> x, vector<int> y){
    
   vector<int> z(0);  //stores the product

//description of the following instructions 
//will be in the report.            
   for(int i = (y.size() - 1); i >= 0; i--){
       
       z.insert (z.begin(), 0);
       
       if(y[i] == 1){
           
           if(z.size() < x.size())
           
                z = add(x, z);
                
            else
            
                z = add(z, x);
       }
   }

   return z;   
}
