#include<iostream>
#include<new>
#include<cstdlib>
#include<cmath>
#include"Narsil.h"
#include<fstream>
//verison 2.0

using namespace std;

//This is a helper function for insert(), it inserts a given point into the tree via recursive calls
int Narsil::insertinnode(node** start, float A, float t, float q2, float w2)
{
  if ((*start) == NULL)
    {
      node* temp = new node;
      if (temp == NULL)
	{
	  return 1;
	}
      temp->A = A;
      temp->t = t;
      temp->q2 = q2;
      temp->w2 = w2;
      temp->ppp = NULL;
      temp->ppn = NULL;
      temp->pnp = NULL;
      temp->npp = NULL;
      temp->pnn = NULL;
      temp->npn = NULL;
      temp->nnp = NULL;
      temp->nnn = NULL;
      (*start) = temp;
      return 0;
    }
  else
    {
      float t1 = t - ((*start)->t);
      float q21 = q2 -((*start)->q2);
      float w21 = w2 - ((*start)->w2);
      if ((t1 > 0) && (q21 > 0) && (w21 > 0))
	{
	  return insertinnode(&((*start)->ppp), A, t, q2, w2);
	}
      else if ((t1 > 0) && (q21 > 0) && ((w21 < 0) || (w21 == 0)))
	{
	  return insertinnode(&((*start)->ppn), A, t, q2, w2);
	}
      else if ((t1 > 0) && ((q21 < 0) || (q21 == 0)) && (w21 > 0))
	{
	  return insertinnode(&((*start)->pnp), A, t, q2, w2);
	}
      else if (((t1 < 0) || (t1 == 0)) && (q21 >0) && (w21 > 0))
	{
	  return insertinnode(&((*start)->npp), A, t, q2, w2);
	}
      else if ((t1 > 0) && ((q21 < 0) || (q21 == 0)) && ((w21 < 0) || (w21 == 0)))
	{
	  return insertinnode(&((*start)->pnn), A, t, q2, w2);
	}
      else if (((t1 < 0) || (t1 = 0)) && (q21 > 0) && ((w21 < 0) || (w21 == 0)))
	{
	  return insertinnode(&((*start)->npn), A, t, q2, w2);
	}
      else if (((t1 < 0) || (t1 == 0)) && ((q21 < 0) || (q21 == 0)) && (w21 > 0))
	{
	  return insertinnode(&((*start)->nnp), A, t, q2, w2);
	}
      else if (((t1 < 0) || (t1 == 0)) && ((q21 < 0) || (q21 == 0)) && ((w21 < 0) || (w21 == 0)))
	{
	  return insertinnode(&((*start)->nnn), A, t, q2, w2);
	}
      else
	{
	  return 2;
	}
    }
}

//This is method is called by the user to insert a point in the tree, makes use of insertinnode() for the insertion
int Narsil::insert(float A, float t, float q2, float w2)
{
  if (root == NULL)
    {
      node* temp = new node;
      if (temp == NULL)
	{
	  return 1;
	}
      temp->A = A;
      temp->t = t;
      temp->q2 = q2;
      temp->w2 = w2;
      temp->ppp = NULL;
      temp->ppn = NULL;
      temp->pnp = NULL;
      temp->npp = NULL;
      temp->pnn = NULL;
      temp->npn = NULL;
      temp->nnp = NULL;
      temp->nnn = NULL;
      root = temp;
      maxval[0] = abs(t);
      maxval[1] = abs(q2);
      maxval[2] = abs(w2);
      return 0;
    }
  else
    {
      float t1 = t - (root->t);
      float q21 = q2 -(root->q2);
      float w21 = w2 - (root->w2);
      if (abs(t) > maxval[0])
	{
	  maxval[0] = abs(t);
	}
      if (abs(q2) > maxval[1])
	{
	  maxval[1] = abs(q2);
	}
      if (abs(w2) > maxval[2])
	{
	  maxval[2] = abs(w2);
	}
      if ((t1 > 0) && (q21 > 0) && (w21 > 0))
	{
	  insertinnode(&(root->ppp), A, t, q2, w2);
	  return 0;
	}
      else if ((t1 > 0) && (q21 > 0) && ((w21 < 0) || (w21 == 0)))
	{
	  insertinnode(&(root->ppn), A, t, q2, w2);
	  return 0;
	}
      else if ((t1 > 0) && ((q21 < 0) || (q21 == 0)) && (w21 > 0))
	{
	  insertinnode(&(root->pnp), A, t, q2, w2);
	  return 0;
	}
      else if (((t1 < 0) || (t1 == 0)) && (q21 >0) && (w21 > 0))
	{
	  insertinnode(&(root->npp), A, t, q2, w2);
	  return 0;
	}
      else if ((t1 > 0) && ((q21 < 0) || (q21 == 0)) && ((w21 < 0) || (w21 == 0)))
	{
	  insertinnode(&(root->pnn), A, t, q2, w2);
	  return 0;
	}
      else if (((t1 < 0) || (t1 = 0)) && (q21 > 0) && ((w21 < 0) || (w21 == 0)))
	{
	  insertinnode(&(root->npn), A, t, q2, w2);
	  return 0;
	}
      else if (((t1 < 0) || (t1 == 0)) && ((q21 < 0) || (q21 == 0)) && (w21 > 0))
	{
	  insertinnode(&(root->nnp), A, t, q2, w2);
	  return 0;
	}
      else if (((t1 < 0) || (t1 == 0)) && ((q21 < 0) || (q21 == 0)) && ((w21 < 0) || (w21 == 0)))
	{
	  insertinnode(&(root->nnn), A, t, q2, w2);
	  return 0;
	}
      else
	{
	  return 2;
	}
    }
}

//This is a helper function for treverse(), treverses the tree recursively
void Narsil::treversenode(node** start)
{
  if ((*start) == NULL)
    {
      return;
    }
  else
    {
      cout<<"("<<((*start)->A)<<","<<((*start)->t)<<","<<((*start)->q2)<<","<<((*start)->w2)<<")"<<"\n";
      treversenode(&((*start)->ppp));
      treversenode(&((*start)->ppn));
      treversenode(&((*start)->pnp));
      treversenode(&((*start)->npp));
      treversenode(&((*start)->pnn));
      treversenode(&((*start)->npn));
      treversenode(&((*start)->nnp));
      treversenode(&((*start)->nnn));
    }
}

//This is the method called by the user to treverse a tree
void Narsil::treverse()
{
  if (root == NULL)
    {
      return;
    }
  else
    {
      cout<<"("<<(root->A)<<","<<(root->t)<<","<<(root->q2)<<","<<(root->w2)<<")"<<"\n";
      treversenode(&(root->ppp));
      treversenode(&(root->ppn));
      treversenode(&(root->pnp));
      treversenode(&(root->npp));
      treversenode(&(root->pnn));
      treversenode(&(root->npn));
      treversenode(&(root->nnp));
      treversenode(&(root->nnn));
    }
}

//Used to calculate the distance between the two given points
float Narsil::dist(float t, float q2, float w2, float t1, float q21, float w21)
{
  float res = pow(t-t1,2) + pow(q2-q21,2) + pow(w2-w21,2);
  return res;
}

//This function ensures that the results array holds the points that are closest to the given point as nearest neighbour search is carried out
float** Narsil::updateresults(float** results, float t, float q2, float w2,float A, float t1, float q21, float w21)
{
  float cdist = dist(t,q2,w2,t1,q21,w21);
  float ddist = 0;
  int itr = 0;
  int itr1 = -1;
  int max = 0;
  for(int i = 0; i < 8; i++)
    {
      float tmpd = dist(t,q2,w2,results[i][1],results[i][2],results[i][3]);
      if ((results[i][1] == t1) && (results[i][2] == q21) && (results[i][3] == w21))
	{
	  break;
	}
      if ((results[i][1] == 0) && (results[i][2] == 0) && (results[i][3] == 0))
	{
	  itr1 = i;
	  break;
	}
      if ((tmpd > ddist))
	{
	  max = i;
	  ddist = tmpd;
	}
      if (tmpd > cdist)
	{
	  itr = 1;
	}
    }
  if (itr1 != -1)
    {
      results[itr1][0] = A;
      results[itr1][1] = t1;
      results[itr1][2] = q21;
      results[itr1][3] = w21;
    }
  else if (itr == 1)
    {
      results[max][0] = A;
      results[max][1] = t1;
      results[max][2] = q21;
      results[max][3] = w21;
    }
  return results;
}

//This is the method that is called by the user to carry out nearest neightbour search
float** Narsil::nearestnbh( float t, float q2, float w2)
{
  float** results = new float*[8];
  for(int i = 0; i < 8; i++)
    {
      results[i] = new float[4];
      for(int j = 0; j < 4; j++)
	{
	  results[i][j] = 0.0;
	}
    }
  return nearestnbh1(&root,results,t,q2,w2);
}


//This is the helper function called by nearestnbh(), it searches through the tree recursively for the eight nearest neighbours
float** Narsil::nearestnbh1(node** start,float** results, float t, float q2, float w2)
{
  if ((*start) == NULL)
    {
      return results;
    }
  else
    {
      //float cdist = dist(t, q2, w2, ((*start)->t), ((*start)->q2), ((*start)->w2));
      float walld1 = pow(t - ((*start)->t),2);
      float walld2 = pow(q2 - ((*start)->q2),2);
      float walld3 = pow(w2 - ((*start)->w2),2);
      float t1 = t - ((*start)->t);
      float q21 = q2 - ((*start)->q2);
      float w21 = w2 - ((*start)->w2);
      //float t2 = -t1;
      //float q22 = -q21;
      //float w22 = -w21;
      if ((t1 > 0) && (q21 > 0) && (w21 > 0))
	{
	  results = nearestnbh1(&((*start)->ppp),results, t, q2, w2);
	  //int iter = 0;
	  results = updateresults(results, t, q2, w2, ((*start)->A), ((*start)->t), ((*start)->q2), ((*start)->w2));
	  for(int i = 0; i < 8; i++)
	    {
	      float ddist = dist(t,q2,w2,results[i][1],results[i][2],results[i][3]);
	      //if ((cdist < ddist) || ((results[i][1] == 0) && (results[i][2] == 0) && (results[i][3] == 0) && (iter == 0)))
	      //{
	      //  results[i][0] = (*start)->A;
	      //  results[i][1] = (*start)->t;
	      //  results[i][2] = (*start)->q2;
	      //  results[i][3] = (*start)->w2;
	      //  iter++;
	      //}
	      if ((walld1 < ddist) && (walld2 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->ppn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnn),results, t, q2, w2);
		}
	      else if ((walld1 < ddist) && (walld2 < ddist))
		{
		  results = nearestnbh1(&((*start)->pnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npp),results, t, q2, w2);
		}
	      else if ((walld1 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->ppn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npp),results, t, q2, w2);
		}
	      else if ((walld2 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->ppn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnn),results, t, q2, w2);
		}
	      else if (walld1 < ddist)
		{
		  results = nearestnbh1(&((*start)->npp),results, t, q2, w2);
		}
	      else if (walld2 < ddist)
		{
		  results = nearestnbh1(&((*start)->pnp),results, t, q2, w2);
		}
	      else if (walld3 < ddist)
		{
		  results = nearestnbh1(&((*start)->ppn),results, t, q2, w2);
		}
	    }
	  return results;
	}
      else if ((t1 > 0) && (q21 > 0) && ((w21 < 0) || (w21 == 0)))
	{
	  results = nearestnbh1(&((*start)->ppn),results, t, q2, w2);
	  //int iter = 0;
	  results = updateresults(results, t, q2, w2, ((*start)->A), ((*start)->t), ((*start)->q2), ((*start)->w2));
	  for(int i = 0; i < 8; i++)
	    {
	      float ddist = dist(t,q2,w2,results[i][1],results[i][2],results[i][3]);
	      //if ((cdist < ddist) || ((results[i][1] == 0) && (results[i][2] == 0) && (results[i][3] == 0) && (iter == 0)))
	      //{
	      //  results[i][0] = (*start)->A;
	      //  results[i][1] = (*start)->t;
	      //  results[i][2] = (*start)->q2;
	      //  results[i][3] = (*start)->w2;
	      //  iter++;
	      //}
	      if ((walld1 < ddist) && (walld2 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->ppp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnn),results, t, q2, w2);
		}
	      else if ((walld1 < ddist) && (walld2 < ddist))
		{
		  results = nearestnbh1(&((*start)->pnn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npn),results, t, q2, w2);
		}
	      else if ((walld1 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->ppp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npp),results, t, q2, w2);
		}
	      else if ((walld2 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->ppp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnn),results, t, q2, w2);
		}
	      else if (walld1 < ddist)
		{
		  results = nearestnbh1(&((*start)->npn),results, t, q2, w2);
		}
	      else if (walld2 < ddist)
		{
		  results = nearestnbh1(&((*start)->pnn),results, t, q2, w2);
		}
	      else if (walld3 < ddist)
		{
		  results = nearestnbh1(&((*start)->ppp),results, t, q2, w2);
		}
	    }
	  return results;
	}
      else if ((t1 > 0) && ((q21 < 0) || (q21 == 0)) && (w21 > 0))
	{
	  results = nearestnbh1(&((*start)->pnp),results, t, q2, w2);
	  //int iter = 0;
	  results = updateresults(results, t, q2, w2, ((*start)->A), ((*start)->t), ((*start)->q2), ((*start)->w2));
	  for(int i = 0; i < 8; i++)
	    {
	      float ddist = dist(t,q2,w2,results[i][1],results[i][2],results[i][3]);
	      //if ((cdist < ddist) || ((results[i][1] == 0) && (results[i][2] == 0) && (results[i][3] == 0) && (iter == 0)))
	      //{
	      //  results[i][0] = (*start)->A;
	      //  results[i][1] = (*start)->t;
	      //  results[i][2] = (*start)->q2;
	      //  results[i][3] = (*start)->w2;
	      //  iter++;
	      //}
	      if ((walld1 < ddist) && (walld2 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->ppn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->ppp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnn),results, t, q2, w2);
		}
	      else if ((walld1 < ddist) && (walld2 < ddist))
		{
		  results = nearestnbh1(&((*start)->ppp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnp),results, t, q2, w2);
		}
	      else if ((walld1 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->pnn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnp),results, t, q2, w2);
		}
	      else if ((walld2 < ddist) && (walld3 < ddist)) 
		{
		  results = nearestnbh1(&((*start)->ppn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->ppp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnn),results, t, q2, w2);
		}
	      else if (walld1 < ddist)
		{
		  results = nearestnbh1(&((*start)->npp),results, t, q2, w2);
		}
	      else if (walld2 < ddist)
		{
		  results = nearestnbh1(&((*start)->pnp),results, t, q2, w2);
		}
	      else if (walld3 < ddist)
		{
		  results = nearestnbh1(&((*start)->ppn),results, t, q2, w2);
		}
	    }
	  return results;
	}
      else if (((t1 < 0) || (t1 == 0)) && (q21 >0) && (w21 > 0))
	{
	  results = nearestnbh1(&((*start)->npp),results, t, q2, w2);
	  //int iter = 0;
	  results = updateresults(results, t, q2, w2, ((*start)->A), ((*start)->t), ((*start)->q2), ((*start)->w2));
	  for(int i = 0; i < 8; i++)
	    {
	      float ddist = dist(t,q2,w2,results[i][1],results[i][2],results[i][3]);
	      //if ((cdist < ddist) || ((results[i][1] == 0) && (results[i][2] == 0) && (results[i][3] == 0) && (iter == 0)))
	      //{
	      //  results[i][0] = (*start)->A;
	      //  results[i][1] = (*start)->t;
	      //  results[i][2] = (*start)->q2;
	      //  results[i][3] = (*start)->w2;
	      //  iter++;
	      //}
	      if ((walld1 < ddist) && (walld2 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->ppn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->ppp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnn),results, t, q2, w2);
		}
	      else if ((walld1 < ddist) && (walld2 < ddist))
		{
		  results = nearestnbh1(&((*start)->pnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->ppp),results, t, q2, w2);
		}
	      else if ((walld1 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->ppn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->ppp),results, t, q2, w2);
		}
	      else if ((walld2 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->npn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnn),results, t, q2, w2);
		}
	      else if (walld1 < ddist)
		{
		  results = nearestnbh1(&((*start)->ppp),results, t, q2, w2);
		}
	      else if (walld2 < ddist)
		{
		  results = nearestnbh1(&((*start)->nnp),results, t, q2, w2);
		}
	      else if (walld3 < ddist)
		{
		  results = nearestnbh1(&((*start)->npn),results, t, q2, w2);
		}
	    }
	  return results;
	}
      else if ((t1 > 0) && ((q21 < 0) || (q21 == 0)) && ((w21 < 0) || (w21 == 0)))
	{
	  results = nearestnbh1(&((*start)->pnn), results, t, q2, w2);
	  //int iter = 0;
	  results = updateresults(results, t, q2, w2, ((*start)->A), ((*start)->t), ((*start)->q2), ((*start)->w2));
	  for(int i = 0; i < 8; i++)
	    {
	      float ddist = dist(t,q2,w2,results[i][1],results[i][2],results[i][3]);
	      //if ((cdist < ddist) || ((results[i][1] == 0) && (results[i][2] == 0) && (results[i][3] == 0) && (iter == 0)))
	      //{
	      //  results[i][0] = (*start)->A;
	      //  results[i][1] = (*start)->t;
	      //  results[i][2] = (*start)->q2;
	      //  results[i][3] = (*start)->w2;
	      //  iter++;
	      //}
	      if ((walld1 < ddist) && (walld2 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->ppn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->ppp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnn),results, t, q2, w2);
		}
	      else if ((walld1 < ddist) && (walld2 < ddist))
		{
		  results = nearestnbh1(&((*start)->ppn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnn),results, t, q2, w2);
		}
	      else if ((walld1 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->pnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnn),results, t, q2, w2);
		}
	      else if ((walld2 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->pnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->ppn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->ppp),results, t, q2, w2);
		}
	      else if (walld1 < ddist)
		{
		  results = nearestnbh1(&((*start)->nnn),results, t, q2, w2);
		}
	      else if (walld2 < ddist)
		{
		  results = nearestnbh1(&((*start)->ppn),results, t, q2, w2);
		}
	      else if (walld3 < ddist)
		{
		  results = nearestnbh1(&((*start)->pnp),results, t, q2, w2);
		}
	    }
	  return results;
	}
      else if (((t1 < 0) || (t1 = 0)) && (q21 > 0) && ((w21 < 0) || (w21 == 0)))
	{
	  results = nearestnbh1(&((*start)->npn),results, t, q2, w2);
	  //int iter = 0;
	  results = updateresults(results, t, q2, w2, ((*start)->A), ((*start)->t), ((*start)->q2), ((*start)->w2));
	  for(int i = 0; i < 8; i++)
	    {
	      float ddist = dist(t,q2,w2,results[i][1],results[i][2],results[i][3]);
	      //if ((cdist < ddist) || ((results[i][1] == 0) && (results[i][2] == 0) && (results[i][3] == 0) && (iter == 0)))
	      //{
	      //  results[i][0] = (*start)->A;
	      //  results[i][1] = (*start)->t;
	      //  results[i][2] = (*start)->q2;
	      //  results[i][3] = (*start)->w2;
	      //  iter++;
	      //}
	      if ((walld1 < ddist) && (walld2 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->ppn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->ppp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnn),results, t, q2, w2);
		}
	      else if ((walld1 < ddist) && (walld2 < ddist))
		{
		  results = nearestnbh1(&((*start)->ppn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnn),results, t, q2, w2);
		}
	      else if ((walld1 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->ppn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->ppp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npp),results, t, q2, w2);
		}
	      else if ((walld2 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->npp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnn),results, t, q2, w2);
		}
	      else if (walld1 < ddist)
		{
		  results = nearestnbh1(&((*start)->ppn),results, t, q2, w2);
		}
	      else if (walld2 < ddist)
		{
		  results = nearestnbh1(&((*start)->nnn),results, t, q2, w2);
		}
	      else if (walld3 < ddist)
		{
		  results = nearestnbh1(&((*start)->npp),results, t, q2, w2);
		}
	    }
	  return results;
	}
      else if (((t1 < 0) || (t1 == 0)) && ((q21 < 0) || (q21 == 0)) && (w21 > 0))
	{
	  results = nearestnbh1(&((*start)->nnp),results, t, q2, w2);
	  //int iter = 0;
	  results = updateresults(results, t, q2, w2, ((*start)->A), ((*start)->t), ((*start)->q2), ((*start)->w2));
	  for(int i = 0; i < 8; i++)
	    {
	      float ddist = dist(t,q2,w2,results[i][1],results[i][2],results[i][3]);
	      //if ((cdist < ddist) || ((results[i][1] == 0) && (results[i][2] == 0) && (results[i][3] == 0) && (iter == 0)))
	      //{
	      //  results[i][0] = (*start)->A;
	      //  results[i][1] = (*start)->t;
	      //  results[i][2] = (*start)->q2;
	      //  results[i][3] = (*start)->w2;
	      //  iter++;
	      //}
	      if ((walld1 < ddist) && (walld2 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->ppn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->ppp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnn),results, t, q2, w2);
		}
	      else if ((walld1 < ddist) && (walld2 < ddist))
		{
		  results = nearestnbh1(&((*start)->pnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->ppp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npp),results, t, q2, w2);
		}
	      else if ((walld1 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->pnn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnp),results, t, q2, w2);
		}
	      else if ((walld2 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->npn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnn),results, t, q2, w2);
		}
	      else if (walld1 < ddist)
		{
		  results = nearestnbh1(&((*start)->pnp),results, t, q2, w2);
		}
	      else if (walld2 < ddist)
		{
		  results = nearestnbh1(&((*start)->npp),results, t, q2, w2);
		}
	      else if (walld3 < ddist)
		{
		  results = nearestnbh1(&((*start)->nnn),results, t, q2, w2);
		}
	    }
	  return results;
	}
      else if (((t1 < 0) || (t1 == 0)) && ((q21 < 0) || (q21 == 0)) && ((w21 < 0) || (w21 == 0)))
	{
	  results = nearestnbh1(&((*start)->nnn),results, t, q2, w2);
	  //int iter = 0;
	  results = updateresults(results, t, q2, w2, ((*start)->A), ((*start)->t), ((*start)->q2), ((*start)->w2));
	  for(int i = 0; i < 8; i++)
	    {
	      float ddist = dist(t,q2,w2,results[i][1],results[i][2],results[i][3]);
	      //if ((cdist < ddist) || ((results[i][1] == 0) && (results[i][2] == 0) && (results[i][3] == 0) && (iter == 0)))
	      //{
	      ///  results[i][0] = (*start)->A;
	      // results[i][1] = (*start)->t;
	      //  results[i][2] = (*start)->q2;
	      //  results[i][3] = (*start)->w2;
	      //  iter++;
	      //}
	      if ((walld1 < ddist) && (walld2 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->ppn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->ppp),results, t, q2, w2);
		}
	      else if ((walld1 < ddist) && (walld2 < ddist))
		{
		  results = nearestnbh1(&((*start)->pnn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->ppn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npn),results, t, q2, w2);
		}
	      else if ((walld1 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->pnn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->pnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnp),results, t, q2, w2);
		}
	      else if ((walld2 < ddist) && (walld3 < ddist))
		{
		  results = nearestnbh1(&((*start)->npn),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->nnp),results, t, q2, w2);
		  results = nearestnbh1(&((*start)->npp),results, t, q2, w2);
		}
	      else if (walld1 < ddist)
		{
		  results = nearestnbh1(&((*start)->pnn),results, t, q2, w2);
		}
	      else if (walld2 < ddist)
		{
		  results = nearestnbh1(&((*start)->npn),results, t, q2, w2);
		}
	      else if (walld3 < ddist)
		{
		  results = nearestnbh1(&((*start)->nnp),results, t, q2, w2);
		}
	    }
	  return results;
	}
      else
	{
	  return results;
	}
      
    }
}

//This is a method called by the user to delete a particular point from a tree
int Narsil::ndelete(float A, float t, float q2, float w2)
{
  if (root == NULL)
    {
      return 1;
    }
  else
    {
      if ((root->A == A) && (root->t == t) && (root->q2) && (root->w2 == w2))
	{
	  insertinto(&(root->ppp),&(root->ppn));
	  insertinto(&(root->ppp),&(root->pnp));
	  insertinto(&(root->ppp),&(root->npp));
	  insertinto(&(root->ppp),&(root->pnn));
	  insertinto(&(root->ppp),&(root->npn));
	  insertinto(&(root->ppp),&(root->nnp));
	  insertinto(&(root->ppp),&(root->nnn));
	  root = root->ppp;
	  return 0;
	}
      else
	{
	  return indelete(&root, A, t, q2, w2);
	}
    }
}

//This is helper function for ndelete()
int Narsil::insertinto(node** reciever, node** donor)
{
  if ((*donor) == NULL)
    {
      return 1;
    }
  else
    {
      insertinnode(reciever, (*donor)->A, (*donor)->t, (*donor)->q2, (*donor)->w2);
      insertinto(reciever,&((*donor)->ppp));
      insertinto(reciever,&((*donor)->ppn));
      insertinto(reciever,&((*donor)->pnp));
      insertinto(reciever,&((*donor)->npp));
      insertinto(reciever,&((*donor)->pnn));
      insertinto(reciever,&((*donor)->npn));
      insertinto(reciever,&((*donor)->nnp));
      insertinto(reciever,&((*donor)->nnn));
      return 0;
    }
}

//This is a helper function to ndelete(), it find the required node recursively and deletes it 
int Narsil::indelete(node** start, float A, float t, float q2, float w2)
{
  if ((*start) == NULL)
    {
      return 1;
    }
  else if (((*start)->A == A) && ((*start)->t == t) && ((*start)->q2 == q2) && ((*start)->w2 == w2))
    {
      insertinto(&((*start)->ppp),&((*start)->ppn));
      insertinto(&((*start)->ppp),&((*start)->pnp));
      insertinto(&((*start)->ppp),&((*start)->npp));
      insertinto(&((*start)->ppp),&((*start)->pnn));
      insertinto(&((*start)->ppp),&((*start)->npn));
      insertinto(&((*start)->ppp),&((*start)->nnp));
      insertinto(&((*start)->ppp),&((*start)->nnn));
      return -1; 
    }
  else
    {
      float t1 = t - ((*start)->t);
      float q21 = q2 - ((*start)->q2);
      float w21 = w2 - ((*start)->w2);
      if ((t1 > 0) && (q21 > 0) && (w21 > 0))
	{
	  int chk = indelete(&((*start)->ppp), A, t, q2, w2);
	  if (chk == -1)
	    {
	      node* tmp = (*start)->ppp;
	      (*start)->ppp = (*start)->ppp->ppp;
	      delete tmp;
	    }
	  return 0;
	}
      else if ((t1 > 0) && (q21 > 0) && ((w21 < 0) || (w21 == 0)))
	{
	  int chk = indelete(&((*start)->ppn), A, t, q2, w2);
	  if (chk == -1)
	    {
	      node* tmp = (*start)->ppn;
	      (*start)->ppn = (*start)->ppn->ppp;
	      delete tmp;
	    }
	  return 0;
	}
      else if ((t1 > 0) && ((q21 < 0) || (q21 == 0)) && (w21 > 0))
	{
	  int chk = indelete(&((*start)->pnp), A, t, q2, w2);
	  if (chk == -1)
	    {
	      node* tmp = (*start)->pnp;
	      (*start)->pnp = (*start)->pnp->ppp;
	      delete tmp;
	    }
	  return 0;
	}
      else if (((t1 < 0) || (t1 == 0)) && (q21 > 0) && (w21 > 0))
	{
	  int chk = indelete(&((*start)->npp), A, t, q2, w2);
	  if (chk == -1)
	    {
	      node* tmp = (*start)->npp;
	      (*start)->npp = (*start)->npp->ppp;
	      delete tmp;
	    }
	  return 0;
	}
      else if ((t1 > 0) && ((q21 < 0) || (q21 == 0)) && ((w21 < 0) || (w21 == 0)))
	{
	  int chk = indelete(&((*start)->pnn), A, t, q2, w2);
	  if (chk == -1)
	    {
	      node* tmp = (*start)->pnn;
	      (*start)->pnn = (*start)->pnn->ppp;
	      delete tmp;
	    }
	  return 0;
	}
      else if (((t1 < 0) || (t1 == 0)) && (q21 > 0) && ((w21 < 0) && (w21 == 0)))
	{
	  int chk = indelete(&((*start)->npn), A, t, q2, w2);
	  if (chk == -1)
	    {
	      node* tmp = (*start)->npn;
	      (*start)->npn = (*start)->npn->ppp;
	      delete tmp;
	    }
	  return 0;
	}
      else if (((t1 < 0) || (t1 == 0)) && ((q21 < 0) || (q21 == 0)) && (w21 > 0))
	{
	  int chk = indelete(&((*start)->nnp), A, t, q2, w2);
	  if (chk == -1)
	    {
	      node* tmp = (*start)->nnp;
	      (*start)->nnp = (*start)->nnp->ppp;
	      delete tmp;
	    }
	  return 0;
	}
      else if (((t1 < 0) || (t1 == 0)) && ((q21 < 0) || (q21 == 0)) && ((w21 < 0) || (w21 == 0)))
	{
	  int chk = indelete(&((*start)->nnn), A, t, q2, w2);
	  if (chk == -1)
	    {
	      node* tmp = (*start)->nnn;
	      (*start)->nnn = (*start)->nnn->ppp;
	      delete tmp;
	    }
	  return 0;
	}
      else
	{
	  return 1;
	}
    }
}

//This is a helper function that copies data from one tree to another
int Narsil::copyto(Narsil* second)
{
  if (second == NULL)
    {
      return 1;
    }
  else
    {
      return insertinto(&((*second).root),&root);
    }
}

//This is a very rudimentary procedure to interpolate given the eight nearest neighbours
float Narsil::interpolate(float t, float q2, float w2)
{
  if ((maxval[0] < abs(t)) || (maxval[1] < q2) || (maxval[2] < w2))
    {
      return 1.0;
    }
  else
    {
      float** nearnbh = nearestnbh(t,q2,w2);
      float result = 0;
      float td = 0;
      for (int i = 0; i < 7; i++)
	{
	  float dl = dist(nearnbh[i][1],nearnbh[i][2],nearnbh[i][3],t,q2,w2);
	  result = result +(1.0/dl)*nearnbh[i][0];
	  td = td + (1.0/dl);
	}
      return result/td;
    }
}

//This method if to save the data to a given file, appropriate permissions are required
int Narsil::writetofile(string filename)
{
  ofstream datafile;
  datafile.open(filename, ios::out | ios::app);
  if (!datafile)
    {
      cout<<"Error opening file\n";
      return 1;
    }
  else
    {
      datafile<<"\nThe following points are inserted in the tree: \n\n"<<"("<<(root->A)<<","<<(root->t)<<","<<(root->q2)<<","<<(root->w2)<<")"<<"\n";
      writenode(&datafile,&(root->ppp));
      writenode(&datafile,&(root->ppn));
      writenode(&datafile,&(root->pnp));
      writenode(&datafile,&(root->npp));
      writenode(&datafile,&(root->pnn));
      writenode(&datafile,&(root->npn));
      writenode(&datafile,&(root->nnp));
      writenode(&datafile,&(root->nnn));
    }
  datafile.close();
  return 0;
}

//Helper function to writetofile()
int Narsil::writenode(ofstream* filename, node** start)
{
 if ((*start) == NULL)
    {
      return 1;
    }
  else
    {
      (*filename)<<"("<<((*start)->A)<<","<<((*start)->t)<<","<<((*start)->q2)<<","<<((*start)->w2)<<")"<<"\n";
      writenode(filename,&((*start)->ppp));
      writenode(filename,&((*start)->ppn));
      writenode(filename,&((*start)->pnp));
      writenode(filename,&((*start)->npp));
      writenode(filename,&((*start)->pnn));
      writenode(filename,&((*start)->npn));
      writenode(filename,&((*start)->nnp));
      writenode(filename,&((*start)->nnn));
      return 0;
    } 
}

