#include"linkstack.h"
void initstack(Linkstack& S) {
    S = NULL;
}

bool stackempty(Linkstack& S) {//bool类型判断栈是否为空
    if (S == NULL) {
        std::cout << "栈为空" << std::endl;
        return true;
    }
    else {
        std::cout << "栈不为空" << std::endl;
        return false;
    }
}

status push_stack(Linkstack& S, lselemtype& e) {
    Linkstack p = new LNode;
    p->data = e;
    p->next = S;
    S = p;
    return OK;
}

status pop_stack(Linkstack& S, lselemtype& e) {//栈顶元素出栈
    if (S == NULL) {
        std::cout << "栈为空，无法出栈" << std::endl;
        return ERROR;
    }
        Linkstack p;
        p=S;
        e = p->data;
        S = S->next;
        delete p;
    return OK;
}
lselemtype GetTop(Linkstack S) {
    if (S == NULL) {
        std::cout << "栈为空，无栈顶元素" << std::endl;
        return '\0'; // 空栈返回空字符
    }
    return S->data;
}
status Traverse(Linkstack S) {
    if (S == NULL) {
        std::cout << "栈为空" << std::endl;
        return ERROR;
    }
    else
    std::cout << "栈中元素为:";
    Linkstack p = S;
    while (p != NULL) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
    return OK;
}
status Clearstack(Linkstack& S) {
    Linkstack p, q;
    p = S;
    while (p != NULL) {
        q = p;//q暂时指向p指向的结点
        p = p->next;//
        delete q;
    }
    S = NULL;
    std::cout << "栈已清空" << std::endl;
    return OK;
}
status Destroystack(Linkstack& S) {
    Clearstack(S); // 调用清空栈的函数完成销毁
    std::cout << "栈已销毁" << std::endl;
    return OK;
}