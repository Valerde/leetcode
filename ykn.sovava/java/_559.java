package java;

import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.concurrent.SynchronousQueue;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月11日 19:19
 **/
public class _559 {
    // Definition for a Node.
    class Node {
        public int val;
        public List<Node> children;

        public Node() {
        }

        public Node(int _val) {
            val = _val;
        }

        public Node(int _val, List<Node> _children) {
            val = _val;
            children = _children;
        }
    }


    class Solution {
        int max = 0;

        public int maxDepth(Node root) {
            if (root == null) return 0;
            Queue<Node> queue = new LinkedList<>();
            queue.offer(root);
            int size = queue.size();
            while (!queue.isEmpty()) {
                size = queue.size();
                while (size > 0) {
                    Node node = queue.poll();
                    for (Node node1 : node.children) queue.offer(node1);
                    size--;
                }
                max++;

            }
            return max;

        }


    }


    public int maxDepth(Node root) {
        int max = 0;
        if (root == null) return 0;
        List<Node> children = root.children;
        for (Node node : children) {
            int temp = maxDepth(node);
            max = Math.max(temp,max);

        }
        return max+1;


    }
}
