  #include <iostream>
  #include <fstream>
//  #include <stdlib.h>
  
  using namespace std;
  
  int main(int argc, char **arg)
  {
      char string[512];
      ifstream file;
      file.open("FunctionPtr.cpp");
      if(!file)
      {
          cout<<"open file error"<<endl;             
      }
      
      while(!file.eof())
      {
          file.getline(string, 512, '\n');
          cout<<string<<endl;
      }
      system("pause");
      return 0;
  }
