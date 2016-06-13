
#include <string>
#include <cassert>

using namespace std;

enum Type{  // types of node
    OPERAND,    // operand
    UNARY,      // unary operation
    BINARY,     //binary operation
    };


class Node{
    public:
        Node(string);
        ~Node();

        Node* left;
        Node* right;
        Type type;
        union{  // node data can share the space
            char text;
            };

        string print(); // just for test (export .dot text format for graphviz)



    };

void clean (string&);   //  remove unwanted chars
bool udef(string s); //if undefined (!)
bool efin(string s); //if etat final (#)


// main constants
//------------------------------------------------------------------------------
string chars = "ab£.*U^()";  // All allowed chars

const string unaryOp = "*^";                                // Unary Operations
const string binaryOp = ".U";                              // Binary Operations
string operands = "ab£";      // Operands
const string brackets = "()";                               // Brackets

string priorityString = "U.^*ab£"; // priority process

// secondary functions
//------------------------------------------------------------------------------
void clean(string& s){     //  remove unwanted chars
    string r="";
    for(unsigned int i=0;i<s.size();i++){
        if(chars.find(s[i],0)!=string::npos) r+=s[i];
        };
    s = r;
    return;
    }

void cleanBrackets(string& s){     //  remove unwanted external brackets
    int bracketFlag = 0;
    while(s[0]=='(' && s[s.size()-1]==')'){
        unsigned int i=0;
        for(i=0;i<s.size();i++){
            if(s[i]=='(') bracketFlag++;
            if(s[i]==')') bracketFlag--;
            if(bracketFlag==0) break;
            };
        if(i==s.size()-1){
            s.erase(0,1);
            s.erase(s.size()-1,1);
            }
            else break;
        };
    return;
    }

Type getType(char c){   // get the type of a char
    if(unaryOp.find(c,0)!=string::npos) return UNARY;
    else if(binaryOp.find(c,0)!=string::npos) return BINARY;
        else return OPERAND;
    };

// primary functions
//------------------------------------------------------------------------------
Node::Node(string s){   // contructor
    left=NULL;
    right=NULL;

    cleanBrackets(s);   // cleaning external brackets

    int bracketFlag=0;
    bool foundFlag=false;

    for(unsigned  int j=0;j<priorityString.size();j++){   // scan the priority string
        bracketFlag=0;
        for(unsigned  int i=0;i<s.size();i++){        // scan the formula (input) string
            switch(s[i]){
                case '(': bracketFlag++; break;
                case ')': bracketFlag--; break;
                default:
                    if (bracketFlag==0 && s[i]==priorityString[j]){
                        foundFlag = true;   // comparing ok

                        text = s[i];        // save data & type of this node
                        type = getType(s[i]);

                        switch(type){       // next child nodes
                            case BINARY: right=new Node(s.substr(i+1)); // binary
                            case UNARY: left=new Node(s.substr(0,i));   // binary & unary
                            //default:   // operand has no child node
                            };

                        };
                };  // switch s[i] end
            if (foundFlag==true) break;
            };  // for i loop end
        if (foundFlag==true) break;
        };  // for j loop end
    } // Node contructor end


Node::~Node(){      // destructor
    delete left;
    delete right;
    }

string Node::print(){ // for test (.dot format for graphviz - use GVedit)
    string r="";
    if(left!=NULL){
        r += "\"";
        r += text;
        r += "\" -> \"";
        r += left->text;
        r += "\" ;\n";
        };
    if(right!=NULL){
        r += "\"";
        r += text;
        r += "\" -> \"";
        r += right->text;
        r += "\" ;\n";
        };
    if(left!=NULL) r+= left->print();
    if(right!=NULL) r+= right->print();
    return r;
    };

///////////////////////////



string mot(Node *N)
{ string s=" ",p,q;
s[0]=N->text;
if (getType(N->text)==OPERAND) return (s);
    else {p=mot(N->left);

        switch (N->text)
                {
                 case '.':q=mot(N->right);
                        if (p=="£") return(q);
                           else { if (q=="£") return(p);
                                else return (p+'.'+q);
                                }
                                break;
                 case 'U':q=mot(N->right);
                            if (p=="£" && q=="£") return("£");
                                else return ('('+p+'U'+q+')');
                                break;
                  case '*':if (p=="£") return("£");
                           else return ('('+p+')'+'*');break;
                 default :return "£";
                 };
          }
}



//derivee d'arbre
Node *derivee(Node *N,char ch)
{ Node *n=NULL,*nx,*node1,*node2;
string s="";
if (N!=NULL){
 if (getType(N->text)==OPERAND) {
                        if (N->text==ch) { n=new Node("£");
                                                n->left=NULL;
                                                n->right=NULL;
                                                n->type=OPERAND;}
                         else  n=NULL;

                         }
    else switch (N->text)
                {
                 case '.':   if (N->left->text=='*')
                                { node1=derivee(N->left,ch);
                                  node2=derivee(N->right,ch);
                                  //test vides
                                   if (node1==NULL)
                                        {if (node2==NULL) n=NULL;
                                         else n=node2;}
                                 else
                                         { n=new Node("£.£");
                                       n->left=node1;
                                       n->right=N->right;
                                       n->type=BINARY;

                                         if (node2!=NULL)
                                                        {
                                                         nx=new Node("£U£");
                                                         nx->left=n;
                                                          nx->right=node2;
                                                           nx->type=BINARY;
                                                           n=nx;
                                                          }

                                             }

                                 }
                                else {

                                node1=derivee(N->left,ch);
                                 if (node1==NULL) n=NULL;
                                 else      { n=new Node("£.£");
                                            n->left=node1;
                                            n->right=N->right;
                                            n->type=BINARY;
                                                }
                                    }


                         break;



                 case 'U':node1=derivee(N->left,ch);
                          node2=derivee(N->right,ch);
                         if (node1==NULL)
                         {if (node2==NULL) n=NULL;
                          else n=node2;}
                          else
                          {if (node2==NULL) n=node1;
                          else {n=new Node("£U£");
                                    n->left=node1;
                                    n->right=node2;
                                     n->type=BINARY;}
                           };
                           break;
                 case '*':node1=derivee(N->left,ch);
                          if (node1==NULL) n=NULL;
                          else {n=new Node("£.£");
                                    n->left=node1;
                                    n->right=N;
                                     n->type=BINARY;}

                          break;
                 };
             };
  return (n);

}

bool final(Node *N)
{bool f=false;
switch (N->text)
{case '£':f=true;break;
 case '*':f=true;break;
 case '.':f=final(N->left) && final(N->right);break;
 case 'U':f=final(N->left) || final(N->right);break;
 default :f=false;break;
 }
 return f;
  }








