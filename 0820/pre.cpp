#include <iostream>
struct TreeNode{
   double m_data;
   TreeNode* m_left;
   TreeNode* m_right;
   TreeNode(double data) : m_data(data), m_left(nullptr), m_right(nullptr) {}
};
double sumOfSingleParentNodes(TreeNode *ptr){
   if (!ptr) return 0;
   double sum = 0.0;
   if ((ptr->m_left && !ptr->m_right) || (!ptr->m_left && ptr->m_right)) sum += ptr->m_data;
   return sum + sumOfSingleParentNodes(ptr->m_left) + sumOfSingleParentNodes(ptr->m_right);
}
bool getYourKicksOnRoute66Help(TreeNode* node, double target, double product){
    if (!node) return false;  
    product *= node->m_data;   
    if (!node->m_left && !node->m_right)  return product == target;  
    return getYourKicksOnRoute66Help(node->m_left, target, product) || getYourKicksOnRoute66Help(node->m_right, target, product);
}
bool getYourKicksOnRoute66(double target){
   return getYourKicksOnRoute66(root, target, 1);
}
// int main(){
//    TreeNode* root = new TreeNode(4.41);
//    root->m_left = new TreeNode(2.2);
//    root->m_right = new TreeNode(5.5);

//    root->m_left->m_left = new TreeNode(1.36);
//    root->m_right->m_right = new TreeNode(7.93);
//    std::cout << sumOfSingleParentNodes(root) << std::endl;
// }

int main(){
   TreeNode* root = new TreeNode(4);
   root->m_left = new TreeNode(2);
   root->m_right = new TreeNode(5);

   root->m_left->m_left = new TreeNode(1);
   root->m_left->m_right = new TreeNode(3);
   root->m_right->m_right = new TreeNode(7);
   std::cout << getYourKicksOnRoute66Help(root, 24, 1) << std::endl;
}