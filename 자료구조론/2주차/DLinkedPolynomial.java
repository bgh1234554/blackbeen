package cse2010.homework2;

import org.w3c.dom.traversal.NodeFilter;

import java.util.Arrays;
import java.util.stream.Collectors;

/*
 * © 2020 CSE2010 HW #2
 *
 * You can freely modify this class except the signatures of the public methods!!
 */
public class DLinkedPolynomial implements Polynomial {

    private DLinkedList<Term> list = null;

    public DLinkedPolynomial() {
        list = new DLinkedList<>();
    }

    public int getDegree() {
        if(list.isEmpty()){
            return 0;
        }
        return list.getFirstNode().getInfo().expo; // you may delete this line
    }

    @Override
    public double getCoefficient(final int expo) {
        Node<Term> term = list.find(new Term(0.0, expo), Term::compareExponents);
        return term.getInfo().coeff;
    }

    private Term addTerms(Term x, Term y) {
        return new Term(x.coeff + y.coeff, x.expo);
    }

    @Override
    public Polynomial add(final Polynomial p) {
        if(((DLinkedPolynomial)p).list.isEmpty()){
            return this;
        }
        DLinkedPolynomial pol = new DLinkedPolynomial();
        Node<Term> cur = list.getFirstNode();
        while(cur!=list.getLastNode().getNext()){
            pol.addTerm(cur.getInfo().coeff,cur.getInfo().expo);
            cur = cur.getNext();
        }
        Node<Term> cur2 = ((DLinkedPolynomial)p).list.getFirstNode();
        while(cur2!=((DLinkedPolynomial)p).list.getLastNode().getNext()){
            pol.addTerm(cur2.getInfo().coeff,cur2.getInfo().expo);
            cur2 = cur2.getNext();
        }
        return pol; // you may delete this line
    }

    private Term multTerms(Term x, Term y) {
        return new Term(x.coeff * y.coeff, x.expo + y.expo);
    }

    @Override
    public Polynomial mult(final Polynomial p) {
        if(((DLinkedPolynomial)p).getDegree()==0 && ((DLinkedPolynomial)p).getCoefficient(0)==1){
            return this;
        }
        DLinkedPolynomial pol = new DLinkedPolynomial();
        Node<Term> cur1 = list.getFirstNode();
        Node<Term> cur2 = ((DLinkedPolynomial)p).list.getFirstNode();
        while(cur1!=list.getLastNode().getNext()){
            while(cur2!=((DLinkedPolynomial)p).list.getLastNode().getNext()){
                Term multi = multTerms(cur1.getInfo(),cur2.getInfo());
                pol.addTerm(multi.coeff,multi.expo);
                cur2 = cur2.getNext();
            }
            cur1 = cur1.getNext();
            cur2 = ((DLinkedPolynomial)p).list.getFirstNode();
        }
        return pol; // you may delete this line
    }

    @Override
    public void addTerm(final double coeff, final int expo){
        if(list.isEmpty()){
            list.addFirst(new Node(new Term(coeff,expo),null,null));
            return;
        }
        Node<Term> term = list.find(new Term(0.0, expo), Term::compareExponents);
        if(term!=null){
            Term newterm = new Term(term.getInfo().coeff+coeff,term.getInfo().expo);
            Node<Term> n = new Node(newterm,null,null);
            list.addAfter(term,n);
            list.remove(term);
            return;
        }
        /* when we couldn't find the same expo in list */
        else{
            Node<Term> cur = list.getFirstNode();
            if(cur.getInfo().expo<expo){
                Term newterm = new Term(coeff,expo);
                Node<Term> n = new Node(newterm,null,null);
                list.addFirst(n);
                return;
            }
            while(cur!=list.getLastNode()) {
                if(cur.getInfo().expo>expo && cur.getNext().getInfo().expo<expo){
                    break;
                }
                cur = cur.getNext();
            }
            if(cur==list.getLastNode()){
                Term newterm = new Term(coeff,expo);
                Node<Term> n = new Node(newterm,null,null);
                list.addLast(n);
                return;
            }
            Term newterm = new Term(coeff,expo);
            Node<Term> n = new Node(newterm,null,null);
            list.addAfter(cur,n);
            return;
        }
    }

    @Override
    public void removeTerm(final int expo) {
        Node<Term> node = list.find(new Term(0, expo), Term::compareExponents);
        if(node==null){
            throw new NoSuchTermExistsException();
        }
        list.remove(node);
    }

    @Override
    public int termCount() {
        return list.size();
    }

    @Override
    public double evaluate(final double val) {
        double count = 0;
        Node<Term> cur = list.getFirstNode();
        while(cur!=list.getLastNode().getNext()){
            count+=cur.getInfo().coeff*Math.pow(val,cur.getInfo().expo);
            cur = cur.getNext();
        }
        return count; // you may delete this line
    }

    private double power(int x,int y){
        if(y==0){
            return 1;
        }
        else{
            int multiple = 1;
            for(int i=1;i<=y;i++){
                multiple *=x;
            }
            return multiple;
        }
    }

    @Override
    public String toString() {
        if (list.isEmpty())
            return "Empty Polynomial";
        else {
            String[] terms = new String[termCount()];
            int i = 0;
            Node<Term> current = list.getFirstNode();
            do {
                if (current.getInfo().expo == 0) {
                    terms[i++] = String.valueOf(current.getInfo().coeff);
                } else if (current.getInfo().expo == 1) {
                    terms[i++] = current.getInfo().coeff + "x";
                } else {
                    terms[i++] = current.getInfo().coeff + "x^" + current.getInfo().expo;
                }
                current = list.getNextNode(current);
            } while (current != null);
            return String.join("+", terms);
        }
    }

}

