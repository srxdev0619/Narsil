#include"fds.h"
#include<string>
#include<fstream>



class Narsil
{
 public:
  int insert(float A, float t, float q2, float w2);
  float** nearestnbh(float t, float q2, float w2);
  void treverse();
  int ndelete(float A, float t, float q2, float w2);
  int copyto(Narsil* second);
  float interpolate(float t, float q2, float w2);
  int writetofile(std::string filename);
  
 private:
  float** nearestnbh1(node** start, float** results,  float t, float q2, float w2);
  node* root = NULL;
  int insertinnode(node** start, float A, float t, float q2, float w2);
  int deletefrmnode(node** start, float A, float t, float q2, float w2);
  void treversenode(node** start);
  float dist(float t, float q2, float w2, float t1,float q21, float w21);
  float** updateresults(float** results, float t, float q2, float w2,float A, float t1, float q21, float w21);
  int indelete(node** start, float A, float t, float q2, float w2);
  int insertinto(node** reciever, node** donor);
  int writenode(std::ofstream* filename, node** start);
  float maxval[6] = {0};
};

