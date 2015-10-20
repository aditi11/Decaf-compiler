#ifndef AST

#define AST

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
using namespace __gnu_cxx;
class expression
{
public:
  expression() { }
  ~expression() { }
  virtual void print() = 0;
};

class statement
{
public:
  statement() { }
  ~statement() { }
  virtual void print() = 0;
};

typedef enum
  {
	UNM,UNN
  }unaryoperators;

typedef enum
  {
	ADD,SUB,PROD,QUO,REM,LT,LE,GT,GE,EE,NE,BAND,BOR
  }binaryoperators;

typedef enum
  {
	EQ,ME,PE
  }assignmentoperators;

class arguments: public expression
{
public:
  char* _type;
  char* _id;
  arguments(char* type, char* id)
  {
    _type=type;
    _id=id;
  }
  ~arguments()
  {
  }
  void print()
  {
    cout<<_type<<" "<<_id;
  }
};

class parameters: public expression
{
public:
  vector<arguments*>* _listofargs;
  parameters(vector<arguments*>* listofargs)
  {
    _listofargs=listofargs;
  }
  ~parameters()
  {
  }
  void print()
  {
    vector<arguments*>::iterator i;
    for(i=_listofargs->begin();i!=_listofargs->end();i++)
      (*i)->print();
  }
};

class vardeclaration: public statement
{
public:
  char* _type;
  vector<char*>* _vars;
  vardeclaration(char* type, vector<char*>* vars)
  {
    _type=type;
    _vars=vars;
  }
  ~vardeclaration()
  {
  }
  void print()
  {
    cout<<_type<<" ";
    vector<char*>::iterator i;
    for(i=_vars->begin();i!=_vars->end();i++)
      cout<<(*i)<<",";
    cout<<";";
  }
};

class block: public statement
{
public:
  vector<statement*>* _vardeclaration;
  vector<statement*>* _s;
  block(vector<statement*>* vardecl,vector<statement*>* s)
  {
    _vardeclaration=vardecl;
    _s=s;
  }
  ~block()
  {
  }
  void print()
  {
    cout<<"{\n";
    vector<statement*>::iterator i;
    for(i=_vardeclaration->begin();i!=_vardeclaration->end();i++)
      {
        (*i)->print();
        cout<<"\n";
      }
    vector<statement*>::iterator j;
    for(j=_s->begin();j!=_s->end();j++)
      {
        (*j)->print();
        cout<<"\n";
      }
    cout<<"}\n";
  }
};

class methoddeclaration : public statement
{
public:
  char* _type;
  char* _id;
  vector<arguments*>* _p;
  block* _b;
  methoddeclaration(char* type, char* id, vector<arguments*>* p, block* b)
  {
    _type=type;
    _id=id;
    _p=p;
    _b=b;
  }
  ~methoddeclaration()
  {
  }
  void print()
  {
    cout<<_type<<" "<<_id<<"(";
    if(_p!=NULL)
    {
   	 vector<arguments*>::iterator i;
   	 for(i=_p->begin();i!=_p->end();i++)
	 {
   	   (*i)->print();
	   cout<<",";
	 }
    }
    cout<<")\n";
    _b->print();
  }
};

class location: public expression
{
public:
  char* _id;
  expression* _expr;
  int _flag;
  location(char* id, expression* expr, int flag)
  {
    _id=id;
    _expr=expr;
    _flag=flag;
  }
  ~location()
  {
  }
  void print()
  {
    cout<<_id;
    if(_flag==2)
      cout<<"[]";
    else if(_flag==3)
      {
        cout<<"[";
        _expr->print();
        cout<<"]";
      }
  }
};

class locationstatement: public statement
{
public:
  location* _loc;
  assignmentoperators _ass;
  expression* _exp;
  locationstatement(location* loc, assignmentoperators ass, expression* exp)
  {
    _loc=loc;
    _ass=ass;
    _exp=exp;
  }
  ~locationstatement()
  {
  }
  void print()
  {
    _loc->print();
    if(_ass==EQ)
      cout<<"=";
    else if(_ass==PE)
      cout<<"+=";
    else if(_ass==ME)
      cout<<"-=";
    _exp->print();
    cout<<";";
  }
};

class methodcall: public expression
{
public:
  char* _id;
  vector<expression*>* _listofargs;
  methodcall(char* id, vector<expression*>* listofargs)
  {
	  cout<<"in methodcall with id "<<id<<endl;
    _id=id;
    _listofargs=listofargs;
    cout<<"size of args: "<<sizeof(listofargs)<<endl;
  }
  ~methodcall()
  {
  }
  void print()
  {
    cout<<_id<<"(";
    if(_listofargs==NULL)
    {
	    cout<<")\n";
	    return;
    }
    vector<expression*>::iterator i;
    for(i=_listofargs->begin();i!=_listofargs->end();i++)
      {
        (*i)->print();
        cout<<",";
      }
    cout<<")\n";
  }
};


class methodcallstatement: public statement
{
public:
  expression* _m;
  methodcallstatement(expression* m)
  {
    _m=m;
  }
  ~methodcallstatement()
  {
  }
  virtual void print()
  {
    _m->print();
    cout<<";"<<endl;
  }
};

class makestringexp: public expression
{
public:
  char* _s;
  makestringexp(char* s)
  {
    _s=s;
  }
  ~makestringexp()
  {
  }
  void print()
  {
    cout<<"\""<<_s<<"\"";
  }
};

class calloutcall: public expression
{
public:
  char* _s;
  vector<expression*>* _listofexpr;
  calloutcall(char* s, vector<expression*>* listofexpr)
  {
    _s=s;
    _listofexpr=listofexpr;
  }
  ~calloutcall()
  {
  }
  void print()
  {
    cout<<"CALLOUT"<<"("<<_s<<",";
    vector<expression*>::iterator i;
    for(i=_listofexpr->begin();i!=_listofexpr->end();i++)
      {
        (*i)->print();
        cout<<",";
      }
  }
};

class field : public statement
{
public:
  int _size;
  char* _id;
  field(char* id, int size)
  {
    _id=id;
    _size=size;
  }
  ~field()
  {
  }
  void print()
  {
    cout<<_id;
    if(_size!=0)
      cout<<"["<<_size<<"]";
  }
};

class fielddeclaration : public statement
{
public:
  char* _type;
  vector<statement*>* _listoffields;
  fielddeclaration(char* type, vector<statement*>* listoffields)
  {
    _type=type;
    _listoffields=listoffields;
 }
  ~fielddeclaration()
  {
  }
  void print()
  {
    cout << _type << " ";
    vector<statement*>::iterator i;
    for(i=_listoffields->begin();i!=_listoffields->begin()+1;i++)
      (*i)->print();
    for(i=_listoffields->begin() + 1;i!=_listoffields->end();i++)
      {
        cout<<",";
        (*i)->print();
      }
  cout<<";" << endl;
  }
};

/*class declaration : public statement
{
	public:
		vector<statement*>* _decls;
		declaration(vector<statement*>* decls)
		{
			_decls=decls;
		}
		~declaration()
		{
		}
		void print()
		{
			vector<statement*>*::iterator i;
			for(i=_decls->begin();i!=_decls->end();i++)
			{
				(*i)->print();
			}
		}
};*/

class ifcondition: public statement
{
public:
  expression* _cond;
  block* _b1;
  block* _b2;
  ifcondition(expression* cond, block* b1, block* b2)
  {
    _cond=cond;
    _b1=b1;
    _b2=b2;
  }
  ~ifcondition()
  {
  }
  void print()
  {
    cout<<"if(";
    _cond->print();
    cout<<")\n";
    _b1->print();
    if(_b2!=NULL)
      {
        cout<<"else\n";
        _b2->print();
      }
  }
};

class forloop: public statement
{
public:
  char* _id;
  expression* _exp1;
  expression* _exp2;
  block* _b;
  forloop(char* id, expression* exp1, expression* exp2, block* b)
  {
    _id=id;
    _exp1=exp1;
    _exp2=exp2;
    _b=b;
  }
  ~forloop()
  {
  }
  void print()
  {
    cout<<"for "<<_id<<"=";
    _exp1->print();
    cout<<",";
    _exp2->print();
    _b->print();
  }
};

class returnstatement: public statement
{
public:
  expression* _exp;
  returnstatement(expression* exp)
  {
    _exp=exp;
  }
  ~returnstatement()
  {
  }
  void print()
  {
    cout<<"return";
    if(_exp!=NULL)
      {
        cout<<" ";
        _exp->print();
      }
    cout<<";\n";
  }
};

class breakstatement: public statement
{
public:
  breakstatement()
  {
  }
  ~breakstatement()
  {
  }
  void print()
  {
    cout<<"break;\n";
  }
};

class continuestatement: public statement
{
public:
  continuestatement()
  {
  }
  ~continuestatement()
  {
  }
  void print()
  {
    cout<<"continue;\n";
  }
};

class stringliteral: public expression
{
public:
  char* _s;
  stringliteral(char* s)
  {
    _s = s;
  }
  ~stringliteral()
  {
  }
  void print()
  {
    cout << _s << endl;
  }
};

class decimalliteral: public expression
{
public:
  int _i;
  decimalliteral(int i)
  {
    _i=i;
  }
  ~decimalliteral()
  {
  }
  void print()
  {
    cout<<_i;
  }
};

class hexliteral: public expression
{
public:
  char* _s;
  hexliteral(char* s)
  {
    _s=s;
  }
  ~hexliteral()
  {
  }
  void print()
  {
    cout<<_s;
  }
};

class charliteral: public expression
{
public:
  char* _c;
  charliteral(char* c)
  {
    _c=c;
  }
  ~charliteral()
  {
  }
  void print()
  {
    cout<<*(_c);
  }
};

class boolliteral: public expression
{
public:
  bool _b;
  boolliteral(bool b) 
  { 
    _b=b; 
  }
  ~boolliteral() 
  {
  }
  void print() 
  { 
    cout<<_b; 
  }
};

class unary: public expression
{
public:
  expression* _exp;
  unaryoperators _u;
  unary(unaryoperators u, expression* exp)
  {
    _u=u;
    _exp=exp;
  }
  ~unary()
  {
  }
  void print()
  {
    switch(_u)
      {
      case UNM:
        cout<<"-";
        break;
      case UNN:
        cout<<"!";
        break;
      }
    _exp->print();
  }
};

class parentheses: public expression
{
public:
  expression* _exp;
  parentheses(expression* exp)
  {
    _exp=exp;
  }
  ~parentheses()
  {
  }
  void print()
  {
    cout<<"(";
    _exp->print();
    cout<<")";
  }
};

class binary: public expression
{
public:
  expression* _exp1;
  expression* _exp2;
  binaryoperators _b;
  binary(expression* exp1, binaryoperators b, expression* exp2)
  {
    _exp1=exp1;
    _exp2=exp2;
    _b=b;
  }
  ~binary()
  {
  }
  void print()
  {

    _exp1->print();
    switch(_b)
      {
      case ADD:
        cout<<"+";
        break;
      case SUB:
        cout<<"-";
        break;
      case PROD:
        cout<<"*";
        break;
      case QUO:
        cout<<"/";
        break;
      case REM:
        cout<<"%";
        break;
      case LT:
        cout<<"<";
        break;
      case LE:
        cout<<"<=";
        break;
      case GT:
        cout<<">";
        break;
      case GE:
        cout<<">=";
        break;
      case EE:
        cout<<"==";
        break;
      case NE:
        cout<<"!=";
        break;
      case BAND:
        cout<<" && ";
        break;
      case BOR:
        cout<<" || ";
      }
    _exp2->print();
  }
};

class head
{
public:
  vector<statement*>* _d;
  //vector<statement*>* _f;
  //declaration* _d;
  head(vector<statement*>* d)
  {
    _d=d;
   // _m=m;
  }
  ~head()
  {
  }
  void print()
  {
    cout<<"class Program\n{\n";
    vector<statement*>::iterator i;
    //cout << "field size = : " << _f->size() << endl;
    for(i = _d->begin(); i != _d->end(); i++)
      {
        (*i)->print();
      }
    //cout << "method size = : " << _m->size() << endl;
    //vector<statement*>::iterator j;
    //for(j = _m->begin(); j != _m->end(); j++)
    //  (*j)->print();
    cout<<"}\n";
  }
};

#endif 
