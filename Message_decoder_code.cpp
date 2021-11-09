#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstring>
#include "ArgumentManager.h"
//remember to remove duplicates from queue holding numbers
using namespace std;
  
  int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
	//string input = "input43.txt";
  //string output = "output.txt";
	string input = am.get("input");
	string output = am.get("output");
  
	ofstream fout(output);
	ifstream iput(input); 

  queue<string> Q, tempQ, deco;
  vector <int> di;
  vector <string> Qi;
  priority_queue<int> priority, priority2;
  int grab, count = 0, flag = 0, flags = 0;

  string code, subCode, decode = "", temp, temp2;

  while (getline(iput, code)){

    while(code == ""){
      getline(iput, code);

    }

      if(code.find("DECODE") != -1){

        //decode = code.substr(code.find("[") + 1);
        //decode = decode.erase(decode.find("]")); 
        
        //deco.push(decode);
       //Q.push(code);
        
        //cout << code << endl;
        temp = code.substr(code.find("(") + 1);
        temp = temp.erase(temp.find(")"));
        stringstream ss(temp);

        ss >> grab;
        di.push_back(-grab);
        Qi.push_back(code);
        priority.push(-grab);
      }
      else{
        Qi.push_back(code);
        //Q.push(code);
        //cout << code << endl;
        temp = code.substr(code.find("(") + 1);
        temp = temp.erase(temp.find(")"));
        stringstream ss(temp);

        ss >> grab;
        //cout << "grab" << grab << endl;
        di.push_back(-grab);
        priority.push(-grab);
      }


  }

  vector <int> vect;
  vector <string> vect2;

  while(!priority.empty()){

    vect.push_back(priority.top());
    for(int i = 0 ; i < di.size() ; i++){

      if(priority.top() == di.at(i)){
        Q.push(Qi.at(i));
        Qi.erase(Qi.begin() + i );
        di.erase(di.begin() + i );
        break;
      }
    }
    priority.pop();
  }


  for( int i = 0 ; i < vect.size() ; i++){

      priority.push(vect.at(i));
      //cout << Q.front() << endl;
      Q.push(Q.front());
      Q.pop();

  }

  
  //cout << endl;
  

  /*while(!priority.empty()){

    vect.push_back(priority.top());
    priority.pop();
  }
  
 

  
    vector<int>::iterator p;
    p = unique(vect.begin(), vect.begin() + vect.size());
    
    
    vect.resize(distance(vect.begin(), p));
    
  for( int i = 0 ; i < vect.size() ; i++){

      priority.push(vect.at(i));
      cout << vect.at(i) << endl;

  }*/
  
  int x = 0;
  string str;
  vector <int> v;
  vector <string> v2;
  while(flag == 0){

    string t = Q.front();

      if(t.find("DECODE") != -1){
        flag = 1;
        decode = t.substr(t.find("[") + 1);
        decode = decode.erase(decode.find("]")); 
        
        deco.push(decode);
        
        Q.pop();
      }
      else{
        Q.pop();
      }
      //cout << Q.front() << endl;
      //Q.push(Q.front());
      

  }
  while(!deco.empty()){

        decode = deco.front();
        
        
        

        //cout << decode << endl << endl; 

  


    

      int  hold = 0;
      code = Q.front();
      /*string stringnum = "";
      stringnum = code.substr(code.find("(") + 1);
      stringnum = stringnum.erase(stringnum.find(")"));

      stringstream s(stringnum);

      s >> hold;*/
          //cout << "here" << " " << code << endl << decode << endl << endl;
      if(code.find("DECODE") != -1){
        flag = 2;
        decode = code.substr(code.find("[") + 1);
        decode = decode.erase(decode.find("]")); 
        
        deco.push(decode);
      }
      else if(code.find("REPLACE") != -1){
          
          subCode = code.substr(code.find("[") + 1);
          string firstComm = subCode.erase(subCode.find(","));
          //cout << endl << subCode << endl;
          subCode = code.substr(code.find("[") + 1);
          string replaceComm = subCode.substr(subCode.find(",") + 1);
          replaceComm = replaceComm.erase(replaceComm.find("]"));
          char a[firstComm.length()], b, c[firstComm.length()], d;
          //cout << "here replace" << endl;
          strcpy(a, firstComm.c_str());
          b = a[0];
          strcpy(c, replaceComm.c_str());
          d = c[0];
          //replaces char with desired char
          
          replace(decode.begin(), decode.end(), b, d);
          
      }
      else if(code.find("REMOVE") != -1){

          subCode = code.substr(code.find("[") + 1);
          string removed = subCode.erase(subCode.find("]"));
          char a[removed.length()], b;
          
          strcpy(a, removed.c_str());
          b = a[0];
          //removes char
          decode.erase(remove(decode.begin(), decode.end(), b), decode.end());
          

      }
      else if(code.find("SWAP") != -1){
          //cout << "here swap" << endl;
          subCode = code.substr(code.find("[") + 1);
          string firstComm = subCode.erase(subCode.find(","));
          subCode = code.substr(code.find("[") + 1);
          string replaceComm = subCode.substr(subCode.find(",") + 1);
          replaceComm = replaceComm.erase(replaceComm.find("]"));

         
          int counts = 0;
          char a[firstComm.length()], b, c[firstComm.length()], d;
          strcpy(a, firstComm.c_str());
          b = a[0];
          strcpy(c, replaceComm.c_str());
          d = c[0];
          for(int i = 0 ; i < decode.length() ; i++){
            
            if(decode.at(i) == b){
              
              decode.at(i) = d;
            }
            else if(decode.at(i) == d){
              
              decode.at(i) = b;
            }
            //cout << "here line 121" << endl;
          }

          

      }
      else if(code.find("ADD") != -1){
        //cout << "here add" << endl;
        subCode = code.substr(code.find("[") + 1);
        string firstComm = subCode.erase(subCode.find(","));
        subCode = code.substr(code.find("[") + 1);
        string replaceComm = subCode.substr(subCode.find(",") + 1);
        replaceComm = replaceComm.erase(replaceComm.find("]"));

        int counts = 0;
        char a[firstComm.length()], b, c[firstComm.length()], d;
        strcpy(a, firstComm.c_str());
        b = a[0];

        for(int i = 0 ; i < decode.length() ; i++){
          if(decode.at(i) == b){
            decode.insert(i+1, replaceComm);
            //cout << "here line 142" << endl;
            
          }

        }

      }
      else if(code.find("PRINT") != -1){

        fout << decode << endl;
        deco.pop();
        flag = 2;

        

      }


      /*v2.push_back(Q.front());
      Q.pop();

    

    for(int i = 0 ; i < v2.size() ; i++){
      Q.push(v2.at(i));
      //cout << v.at(i) << endl;
    }
    v2.clear();*/
    //cout << "here 154" << endl;
    //v.push_back(priority.top());
    Q.pop();
  

    for(int i = 0 ; i < v.size() ; i++){
      priority.push(v.at(i));
      //cout << v.at(i) << endl;
    }
    v.clear();
    x++;
    if(flag != 2){
      deco.push(decode);
      deco.pop();
    }
    flag = 1;
    if(Q.empty()){
      break;
    }
  }


  return 0;
}