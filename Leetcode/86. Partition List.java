class Solution {
    public ListNode partition(ListNode head, int x) {
	
        // If Either there is zero nodes or one node we just reture the head as is
        if (head != null && head.next != null) {
		
            // Case 01: When head's value is greater than or equal to x
            if (head.val >= x) {
			
                // Taking 3 variables to keep track of multiple nodes
                // start Node is the new Node starting where the elements in it are less than x, and startEnd means the ending node in this
                ListNode Curr = head, start = null, startEnd = null;

                while (Curr.next != null) {
				
                    // If curr.next is less than x, we need to move this elemet out of present linkedlist and keep it in 'start'
                    if (Curr.next.val < x) {
					
                        // If no elements in 'start' keep it as first node
                        if (start == null) {
                            start = Curr.next;
                            startEnd = start;
                            Curr.next = start.next;
                        }
						
                        // If elements already exist in 'start', then attach it to the startEnd
                        else {
                            startEnd.next = Curr.next;
                            startEnd = startEnd.next;
                            Curr.next = startEnd.next;
                        }
						
                    }
					
                    // If curr.next value is greate than or equal to x, then move the curr to next element as it is correct order already
                    else {
                        Curr = Curr.next;
                    }
					
                }

                // After finishing above loop, check if any elements added to start or not, incase of no elements then answer is already correct, so just returning head at final
                // Incase if elemnt exists then attach the head to startEnd, and modifying head = start as I am returning head for every case.
                if (start != null) {
                    startEnd.next = head;
                    head = start;
                }
            }
			
            // Case 02: When head's value is less than x
            // For this case the first element is going to stay as is and only the next elements may change according to rules of question, so we just make a recursive call on head.next and assign whatever it return to head.next.
            else {
                head.next = partition(head.next, x);
            }
			
        }
		
        return head;
		
    }
}