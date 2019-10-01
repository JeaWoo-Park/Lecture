#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>



int main() {
   std::ifstream in("워밍업 3번.txt");
   std::ifstream input("워밍업 3번.txt");
   char line[100];

   int word = 0;
   int i = 0;
   char number[100];
   int n = 0;
   
   while (!in.eof()) {   
      i = 0;
      ++word;
      in.getline(line, sizeof(line));
      while (line[i] != NULL) {
         if (line[i] == ' ') {
            ++word; std::cout << "+";
         }
         ++i; 
      }

      std::cout << line << std::endl;
   }
   std::cout << std::endl << "word count: " << word << std::endl;
   std::cout << "number: ";

   while (!input.eof()) {
      i = 0;
      input.getline(line, sizeof(line));
      while (line[i] != NULL) {
         if (line[i] >= '0' && line[i] <= '9') {
            std::cout << line[i];
            if (line[i + 1] == ' ')
               std::cout << " ";
            ++n;
         }
         ++i;
      }
     std::cout << " ";
   }
   
   
   std::cout << "Total: " << n;
   in.close();
}