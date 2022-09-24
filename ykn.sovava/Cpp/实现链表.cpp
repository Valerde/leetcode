/*
��������ʵ�֡�������ѡ��ʹ�õ������˫�����������еĽڵ�Ӧ�þ����������ԣ�val?��?next��val?�ǵ�ǰ�ڵ��ֵ��next?��ָ����һ���ڵ��ָ��/���á����Ҫʹ��˫����������Ҫһ������?prev?��ָʾ�����е���һ���ڵ㡣���������е����нڵ㶼�� 0-index �ġ�

����������ʵ����Щ���ܣ�

get(index)����ȡ�����е�?index?���ڵ��ֵ�����������Ч���򷵻�-1��
addAtHead(val)��������ĵ�һ��Ԫ��֮ǰ���һ��ֵΪ?val?�Ľڵ㡣������½ڵ㽫��Ϊ����ĵ�һ���ڵ㡣
addAtTail(val)����ֵΪ?val �Ľڵ�׷�ӵ���������һ��Ԫ�ء�
addAtIndex(index,val)���������еĵ�?index?���ڵ�֮ǰ���ֵΪ?val? �Ľڵ㡣���?index?��������ĳ��ȣ���ýڵ㽫���ӵ������ĩβ����� index ���������ȣ��򲻻����ڵ㡣���indexС��0������ͷ������ڵ㡣
deleteAtIndex(index)���������?index ��Ч����ɾ�������еĵ�?index ���ڵ㡣
?

*/

class MyLinkedList {
	public:
		MyLinkedList() {
			this->size = 0;
			this->head = new ListNode(0);
		}

		int get(int index) {
			if(index<0||index>=size) {
				return  -1;
			}
			ListNode* cur = head;
			for(int i =0; i<=index; i++) {
				cur = cur->next;
			}
			return cur->val;

		}

		void addAtHead(int val) {
			addAtIndex(0,val);
		}

		void addAtTail(int val) {
			addAtIndex(size,val);
		}

		void addAtIndex(int index, int val) {
			if(index>size) return;

			index= max(0,index);
			size++;
			ListNode *pred = head;
			for(int i = 0; i<index; i++) {
				pred = pred->next;
			}

			ListNode  *toAdd = new ListNode(val);
			toAdd->next = pred->next;
			pred->next = toAdd;



		}

		void deleteAtIndex(int index) {
			if(index<0||index>=size) return;
			size--;
			ListNode *pred = head;
			for(int i = 0; i<index; i++) {
				pred = pred->next;
			}

			ListNode *p = pred->next;
			pred->next = pred->next->next;
			delete p;

		}

	private:
		int size;
		ListNode *head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
