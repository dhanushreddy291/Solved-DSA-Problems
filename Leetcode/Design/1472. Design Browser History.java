class BrowserHistory {

    static class Node {
        Node prev, next;
        String Address;
        Node(String Val) {this.Address = Val;}
        Node(String Val, Node Prev) {
            this.Address = Val;
            this.prev = Prev;
        }
    }
    
    Node Current;
    
    public BrowserHistory(String homepage) {
        Current = new Node(homepage);
    }
    
    public void visit(String url) {
        Current.next = new Node(url, Current);
        Current = Current.next;
    }
    
    public String back(int steps) {
        Node temp = Current;
        while (steps-- > 0 && Current != null) {
            temp = Current;
            Current = Current.prev;
        }
        if (Current != null) return Current.Address;
        else {
            Current = temp;
            return Current.Address;
        }
    }
    
    public String forward(int steps) {
        Node temp = Current;
        while (steps-- > 0 && Current != null) {
            temp = Current;
            Current = Current.next;
        }
        if (Current != null) return Current.Address;
        else {
            Current = temp;
            return Current.Address;
        }
    }
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * String param_2 = obj.back(steps);
 * String param_3 = obj.forward(steps);
 */