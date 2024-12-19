package cse2010.homework5;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class SyntaxTree extends LinkedBinaryTree<String> {

    public static SyntaxTree buildSyntaxTree(String[] expr) {
        SyntaxTree syntax = new SyntaxTree();
        // construct an expression syntax tree ...
        LinkedBinaryTree<String> n = new LinkedBinaryTree<>();
        LinkedBinaryTree<String> n1 = new LinkedBinaryTree<>();
        LinkedBinaryTree<String> n2 = new LinkedBinaryTree<>();
        Stack<LinkedBinaryTree<String>> s = new Stack<>();
        for(int i=0;i<expr.length;i++){
            if(!(expr[i].equals("+")||expr[i].equals("-")||expr[i].equals("*")||expr[i].equals("/"))){
                n.addRoot(expr[i]);
                //System.out.print(expr[i]);
                LinkedBinaryTree<String> tmp = n;
                s.push(tmp);
                n = new LinkedBinaryTree<>();
            }
            else{
                n.addRoot(expr[i]);
                n1 = s.pop();
                n2 = s.pop();
                n.attach(n.root,n2,n1);
                LinkedBinaryTree<String> tmp = n;
                s.push(tmp);
                n = new LinkedBinaryTree<>();
            }
        }
        syntax.addRoot("");
        syntax.attach(syntax.root,s.pop(),new LinkedBinaryTree<>());
        syntax.remove(syntax.root);
        return syntax;
    }



    public String parenthesize() {
        List<Node<String>> snapshot = this.postOrder();
        Stack<String> expr = new Stack<>();
        for(int i=0;i<snapshot.size();i++){
            if(!(snapshot.get(i).getElement().equals("+")|| snapshot.get(i).getElement().equals("-")|| snapshot.get(i).getElement().equals("*")|| snapshot.get(i).getElement().equals("/"))){
                expr.push(snapshot.get(i).getElement());
            }
            else{
                String right = expr.pop();
                String left = expr.pop();
                String fin = "("+left+" "+snapshot.get(i).getElement()+" "+right+")";
                expr.push(fin);
            }
        }

        return expr.peek();
    }

    public double evaluate() {
        double count = 0;
        List<Node<String>> snapshot = this.postOrder();
        Stack<String> expr = new Stack<>();
        for(int i=0;i<snapshot.size();i++){
            if(snapshot.get(i).getElement().equals("+")) {
                double right = Double.parseDouble(expr.pop());
                double left = Double.parseDouble(expr.pop());
                double cnt = (left+right);
                expr.push(Double.toString(cnt));
            }
            else if (snapshot.get(i).getElement().equals("-")){
                double right = Double.parseDouble(expr.pop());
                double left = Double.parseDouble(expr.pop());
                double cnt = (left-right);
                expr.push(Double.toString(cnt));
            }
            else if (snapshot.get(i).getElement().equals("*")){
                double right = Double.parseDouble(expr.pop());
                double left = Double.parseDouble(expr.pop());
                double cnt = (left*right);
                expr.push(Double.toString(cnt));

            }
            else if (snapshot.get(i).getElement().equals("/")){
                double right = Double.parseDouble(expr.pop());
                double left = Double.parseDouble(expr.pop());
                double cnt = (left/right);
                expr.push(Double.toString(cnt));
            }
            else{
                expr.push(snapshot.get(i).getElement());
            }
        }
        return Double.parseDouble(expr.peek());
    }

    public String toPrefix() {
        // you may define helper recursive method and use it here...
        List<Node<String>> snapshot = new ArrayList<>();
        snapshot = this.preOrder();
        String str = "";
        for(int i=0;i<snapshot.size();i++){
            str+= snapshot.get(i).getElement();
            if(i!=snapshot.size()-1){
                str+=" ";
            }
        }
        return str;
    }

    public String indentSyntaxTree() {
        String fin = "";
        List<Node<String>> snapshot = new ArrayList<>();
        snapshot = this.preOrder();
        for(int i=0;i<snapshot.size();i++){
            int j=this.depth(snapshot.get(i));
            for(int k=0;k<2*j;k++){
                fin += " ";
            }
            fin += snapshot.get(i).getElement();
            fin += "\n";
        }
        return fin;
    }

    public static void main(String... args) {

        System.out.println("Homework 5");
    }
}


