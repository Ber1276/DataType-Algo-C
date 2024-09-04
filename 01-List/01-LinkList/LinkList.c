#include <stdio.h>
#include <stdlib.h>


//结构体，变量声明
typedef enum{
    TRUE=1,
    FALSE=0
} boolean;
typedef struct LNode
{
    int data;
    struct LNode *next;
    
}LNode,*LinkList;



/**
 *  功能：创建单链表
 * @param L 单链表头指针()
 * @return 头指针
 */
LinkList InitLinkList(LinkList L){
    L=(LNode *)malloc(sizeof(LNode));
    L->next=NULL;
    return L;
}

/**
 *  功能：检测是否为空单链表
 * @param L 单链表头指针()
 * @return 结果（boolean）
 */
boolean IsEmptyLinkList(LinkList L){
    if (L->next==NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    
    
}

/**
 * 功能：头插法创建单链表
 * @param L 单链表头指针()
 * @param p 从p节点后插入
 * @param e 插入的数据
 * @return 插入结果（boolean）
 */
boolean InsertLinkNode(LinkList L,LNode* p,int e){
    LNode* s=(LNode *)malloc(sizeof(LNode));
    if (!s)
    {
        printf("Memory allocation failed.\n");
        return FALSE;
    }
    if (L->next==NULL&&p!=L)
    {
        printf("The linked list is empty.Please insert from headnode.\n");
        return FALSE;
    }
    
    
    s->data=e;
    s->next=p->next;
    p->next=s;
    return TRUE;
}

/**
 *  功能：删除节点
 * @param L 单链表头指针()
 * @param e 删除p后的数据
 * @return 是否成功删除（boolean）
 */
boolean DeleteLinkNode(LinkList L,LNode* p){
    LNode* tmp=L;
    while (tmp->next!=NULL)
    {
        LNode* pre=tmp;
        tmp=tmp->next;
        if (tmp==p)
        {
            if (tmp->next==NULL)
            {
                pre->next=NULL;
                return TRUE;
            }
            else{
                pre->next=tmp->next;
                return TRUE;
            }
            
        }
    }
    return FALSE;
    
}

/**
 * 功能：打印链表
 * @param L 单链表头指针()
 * return 无
 */
void PrintLinkList(LinkList L){
    LNode* tmp=L->next;
    while (tmp!=NULL)
    {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}

/**
 * 功能：查找某一个数在单链表中是否存在，如果存在返回其地址
 * @param L 单链表头指针()
 * @param x 要查找的数
 * return 存在返回其地址，不存在返回NULL
 */
LNode* FindLinkNode(LinkList L,int x){
    LNode* tmp=L->next;
    while (tmp!=NULL)
    {
        if (tmp->data==x)
        {
            return tmp;
        }
        tmp=tmp->next;
    }
    return NULL;
}

/**
 * 功能：改变单链表中的某个值
 * @param L 单链表头指针()
 * @param p 要修改的节点
 * @param x 新值
 * return 无
 */
void ChangeLinkNode(LinkList L,LNode* p,int x){
    if (p!=NULL)
    {
        p->data=x;
    }
}

int main(){
    LinkList L=InitLinkList(L);
    InsertLinkNode(L,L,1);
    InsertLinkNode(L,L->next,2);
    PrintLinkList(L);
    return 0;
}