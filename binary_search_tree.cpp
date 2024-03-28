#include<iostream>
using namespace std;
class node
{
    string word;
    string mean;
    node *left,*right;
    friend class BST;
};
class BST
{
   node *root;
   public:
   void create_BST(); 
   void call_inorder();
   void inorder_rec(node*root);
   void mirror();
   void mirror_rec(node*root);
   void copy();
   node *copy_rec(node*root);
   void level_wise();
};
class queue
{
    node *q[20];
    int F,R;
    public:
    queue()
    {
        F=-1;
        R=-1;
    }
    void insert(node *t)
    {
        R++;
        q[R]=t;
    }
    node *Delete()
    {
        F++;
        return(q[F]);
    }
    int empty()
    {
        if(F==R)
        return(0);
        else
        return(1);
    }
};
void BST::create_BST()
{
    node *temp;
    node *curr;
    node *root;
    
    char ch;
    
    
    root=new node();
    cout<<"ENTER ROOT WORD";
    cin>>root->word;
    //accept roots mean
    cout<<"ENTER ROOT MEANING";
    cin>>root->mean;
    root->left=root->right=NULL;
    int flag;
    
    cout<<"DO YOU WANT TO ADD NEW NODE";
    cin>>ch;
    
    while(ch== 'y')
    {
        flag=1;
        temp=root;
        curr=new node();
        cout<<"ENTER CURRENT DATA";
        cin>>curr->word;
        cout<<"ENTER CURRENT MEANING";
        cin>>curr->mean;
        curr->left=curr->right=NULL;
        /* code */
     
        while (flag==1);
       {
            if(curr->word<=temp->word)
            {
              if(temp->left==NULL)
              {
                 temp->left=curr;
                 flag=0;
                 break;
              }
              
              else
              {
                  temp=temp->left;
                  flag=1;
              }
            }
            else if(curr->word>=temp->word)
            {
               if(temp->right==NULL)
               {
                   temp->right=curr;
                   flag=0;
                   break;

               }
               
               else
              {
                   temp=temp->right;
                   flag=1;
              }
            }
       }
    
    cout<<"DO YOU WANT TO ADD NEW NODE";
    cin>>ch;
    }
}
void BST::call_inorder()
{
    BST t;
    cout<<"\n INORDER TRAVERSAL";
    t.inorder_rec(root);
}
void BST::inorder_rec(node*root)
{
    if(root!=NULL)
    {
        inorder_rec(root->left);
        cout<<" "<<root->word;
        inorder_rec(root->right);
    }
}
void BST::mirror()
{
    BST t;
    t.mirror_rec(root);
    cout<<"\n MIRROR";
    
}
void BST::mirror_rec(node*root)
{
    node *temp;
    temp=root->left;
    root->left=root->right;
    root->right=temp;
    if(root->left!=NULL)
    {
        mirror_rec(root->left);
    }
    if(root->right!=NULL)
    {
        mirror_rec(root->right);
    }
}
void BST::copy()
{
    node  *t;
    t=copy_rec(root);
    cout<<"\n COPY";
    inorder_rec(t);
    
}
node*BST::copy_rec(node*root)
{
    node *temp=NULL;
    if (root!=NULL)
    {
        temp=new node();
        temp->word=root->word;
        temp->mean=root->mean;
        temp->left=copy_rec(root->left);
        temp->right=copy_rec(root->right);
    }
    return(temp);
}
void BST:: level_wise()
{
    node *temp;
    queue q;
    temp=root;
    q.insert(temp);
    while(q.empty()!=0)
    {
        temp=q.Delete();
        cout<<temp->word<<temp->mean;
        if(temp->left!=NULL)
        q.insert(temp->left);
        if(temp->right!=NULL)
        q.insert(temp->right);
        
    }
}

int main()
{
    BST t;
    t.create_BST();
    t.call_inorder();
    t.mirror();
    t.call_inorder();
    t.copy();
    t.level_wise();

}
   
    

