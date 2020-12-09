//Jorie Noll
// experiment.cpp

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct structArray{
  int one,two,three,four,five,six,seven,eight, nine, ten;
};

int main(int argc, char *argv[]){

  // saves values for x, y, and z from command line arguments
  int x = atoi(argv[1]);
  int y = atoi(argv[2]);
  int z = atoi(argv[3]);

  //array of self-defined structures
  struct structArray structures[x];
  //large 3d array of integers
  int intArrays[10][10][10];
  //tracks average total time
  int average;

//row-major order accessing 3D array intArrays

  //stride 1
  auto begin = high_resolution_clock::now();
  for(int m=0;m<x;m++){
    for(int l=0;l<y;l++){
      for(int k=0;k<z;k++){
        intArrays[m][l][k];
      }
    }
  }
  auto end = high_resolution_clock::now();
  auto time = duration_cast<microseconds>(end - begin);
  average+= time.count();
  cout<<"3D Array Row-Major Order, Stride 1: "<<time.count()<<endl;

  //stride 2
  begin = high_resolution_clock::now();
  for(int m=0;m<x;m+=2){
    for(int l=0;l<y;l+=2){
      for(int k=0;k<z;k+=2){
        intArrays[m][l][k];
      }
    }
  }
  end = high_resolution_clock::now();
  time = duration_cast<microseconds>(end - begin);
  average+= time.count();
  cout<<"3D Array Row-Major Order, Stride 2: "<<time.count()<<endl;


  //stride 3
  begin = high_resolution_clock::now();
  for(int m=0;m<x;m+=3){
    for(int l=0;l<y;l+=3){
      for(int k=0;k<z;k+=3){
        intArrays[m][l][k];
      }
    }
  }
  end = high_resolution_clock::now();
  time = duration_cast<microseconds>(end - begin);
  average+= time.count();
  cout<<"3D Array Row-Major Order, Stride 3: "<<time.count()<<endl;



//column-major order accessing 3D arary intArrays

  //stride 1
  begin = high_resolution_clock::now();
  for(int m=0;m<x;m++){
    for(int l=0;l<y;l++){
      for(int k=0;k<z;k++){
        intArrays[l][m][k];
      }
    }
  }
  end = high_resolution_clock::now();
  time = duration_cast<microseconds>(end - begin);
  average+= time.count();
  cout<<"3D Array Column-Major Order, Stride 1: "<<time.count()<<endl;

  //stride 2
  begin = high_resolution_clock::now();
  for(int m=0;m<x;m+=2){
    for(int l=0;l<y;l+=2){
      for(int k=0;k<z;k+=2){
        intArrays[l][m][k];
      }
    }
  }
  end = high_resolution_clock::now();
  time = duration_cast<microseconds>(end - begin);
  average+= time.count();
  cout<<"3D Array Column-Major Order, Stride 2: "<<time.count()<<endl;

  //stride 3
  begin = high_resolution_clock::now();
  for(int m=0;m<x;m+=3){
    for(int l=0;l<y;l+=3){
      for(int k=0;k<z;k+=3){
        intArrays[l][m][k];
      }
    }
  }
  end = high_resolution_clock::now();
  time = duration_cast<microseconds>(end - begin);
  average+= time.count();
  cout<<"3D Array Column-Major Order, Stride 3: "<<time.count()<<endl;



//depth-major order accessing 3D arary intArrays

  //stride 1
  begin = high_resolution_clock::now();
  for(int m=0;m<x;m++){
    for(int l=0;l<y;l++){
      for(int k=0;k<z;k++){
        intArrays[k][l][m];
      }
    }
  }
  end = high_resolution_clock::now();
  time = duration_cast<microseconds>(end - begin);
  average+= time.count();
  cout<<"3D Array Depth-Major Order, Stride 1: "<<time.count()<<endl;

  //stride 2
  begin = high_resolution_clock::now();
  //stride 2 access data 1 Loop order 3:
  for(int m=0;m<x;m+=2){
    for(int l=0;l<y;l+=2){
      for(int k=0;k<z;k+=2){
        intArrays[k][l][m];
      }
    }
  }
  end = high_resolution_clock::now();
  time = duration_cast<microseconds>(end - begin);
  average+= time.count();
  cout<<"3D Array Depth-Major Order, Stride 2: "<<time.count()<<endl;

  //stride 3
  begin = high_resolution_clock::now();
  for(int m=0;m<x;m+=3){
    for(int l=0;l<y;l+=3){
      for(int k=0;k<z;k+=3){
        intArrays[k][l][m];
      }
    }
  }
  end = high_resolution_clock::now();
  time = duration_cast<microseconds>(end - begin);
  average+= time.count();
  cout<<"3D Array Depth-Major Order, Stride 3: "<<time.count()<<endl;



//accessing structure array structures

  //stride 1
  begin = high_resolution_clock::now();
  for(int m=0;m<x;m++){
    structures[m];
  }
  end = high_resolution_clock::now();
  time = duration_cast<microseconds>(end - begin);
  average+= time.count();
  cout<<"Structure Array, Stride 1: "<<time.count()<<endl;

  //stride 2
  begin = high_resolution_clock::now();
  for(int m=0;m<x;m+=2){
    structures[m];
  }
  end = high_resolution_clock::now();
  time = duration_cast<microseconds>(end - begin);
  average+= time.count();
  cout<<"Structure Array, Stride 2: "<<time.count()<<endl;

  //stride 3
  begin = high_resolution_clock::now();
  for(int m=0;m<x;m+=3){
    structures[m];
  }
  end = high_resolution_clock::now();
  time = duration_cast<microseconds>(end - begin);
  average+= time.count();
  cout<<"Structure Array, Stride 3: "<<time.count()<<endl;

  average = average / 12;
  cout<<"Total Average Time: "<<average<<endl;
}
