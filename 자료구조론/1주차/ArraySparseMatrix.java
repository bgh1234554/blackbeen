package cse2010.homework1;

public class ArraySparseMatrix implements SparseMatrix {

    public static final int DEFAULT_CAPACITY = 1024;

    private int rowCount;
    private int columnCount;
    private int elemCount;
    private Entry[] elements = new Entry[0];

    public ArraySparseMatrix(int rowCount, int columnCount, int capacity) {
        elements = new Entry[capacity];
        this.rowCount = rowCount;
        this.columnCount = columnCount;
        this.elemCount = 0;
    }

    public ArraySparseMatrix(int rowCount, int columnCount) {
        this(rowCount, columnCount, DEFAULT_CAPACITY);
    }

    /*
     * This routine simulates reading from files using two-dimensional matrix.
     */
    public static SparseMatrix create(double[][] aMatrix, int rowCount, int columnCount, int elemCount) {
        ArraySparseMatrix matrix = new ArraySparseMatrix(rowCount, columnCount, elemCount);

        int nonZeroCount = 0;
        for (int i = 0; i < aMatrix.length; i++)
            for (int j = 0; j < aMatrix[i].length; j++) {
                if (Double.compare(aMatrix[i][j], 0.0) != 0) {
                    matrix.put(new Entry(i, j, aMatrix[i][j]));
                    nonZeroCount++;
                }
            }

            if(nonZeroCount!=elemCount) {
            	throw new IllegalStateException("Non zero count doesn't match");
            }
            // if (nonZeroCount != elemCount) throw IllegalStateException saying 
            // "Non zero count doesn't match"
        

        return matrix;
    }

    private void put(Entry entry) {
        elements[elemCount++] = entry;
    }

    @Override
    public SparseMatrix transpose() {
        ArraySparseMatrix matrix2 = new ArraySparseMatrix(columnCount, rowCount, elemCount);
        for(int i=0;i<this.elemCount;i++){
            for(int j=0;j<this.elemCount;j++){
                if(this.elements[j].getCol()==i){
                    int r = this.elements[j].getRow();
                    int c = this.elements[j].getCol();
                    double v = this.elements[j].getValue();
                    matrix2.put(new Entry(c,r,v));
                }
            }
        }
        return matrix2;
    }

    @Override
    public SparseMatrix add(SparseMatrix other) {
        if (this.rowCount != other.getRowCount() || this.columnCount != other.getColumnCount())
            throw new IllegalArgumentException("Matrix size doesn't match");
        ArraySparseMatrix matrix2 = new ArraySparseMatrix(rowCount, columnCount, this.getElemCount()+other.getElemCount());
        int count = 0;
        int i=0, j=0;
        loop:
        for(i=0;i<this.elemCount;i++) {
            for (j=0; j < other.getElemCount(); j++) {
                if(i>=this.elemCount){
                    break loop;
                }
                if ((this.elements[i].getRow() > ((ArraySparseMatrix) other).elements[j].getRow())) {
                    int r = ((ArraySparseMatrix) other).elements[j].getRow();
                    int c = ((ArraySparseMatrix) other).elements[j].getCol();
                    double v = ((ArraySparseMatrix) other).elements[j].getValue();
                    matrix2.put(new Entry(r, c, v));
                    count++;
                } else if ((this.elements[i].getRow() == ((ArraySparseMatrix) other).elements[j].getRow()) && (this.elements[i].getCol() > ((ArraySparseMatrix) other).elements[j].getCol())) {
                    int r = ((ArraySparseMatrix) other).elements[j].getRow();
                    int c = ((ArraySparseMatrix) other).elements[j].getCol();
                    double v = ((ArraySparseMatrix) other).elements[j].getValue();
                    matrix2.put(new Entry(r, c, v));
                    count++;
                } else if ((this.elements[i].getRow() == ((ArraySparseMatrix) other).elements[j].getRow()) && (this.elements[i].getCol() < ((ArraySparseMatrix) other).elements[j].getCol())) {
                    int r = this.elements[i].getRow();
                    int c = this.elements[i].getCol();
                    double v = this.elements[i].getValue();
                    matrix2.put(new Entry(r, c, v));
                    i++;
                    j--;
                    count++;
                } else if (this.elements[i].getRow() < ((ArraySparseMatrix) other).elements[j].getRow()) {
                    int r = this.elements[i].getRow();
                    int c = this.elements[i].getCol();
                    double v = this.elements[i].getValue();
                    matrix2.put(new Entry(r, c, v));
                    i++;
                    j--;
                    count++;
                } else if ((this.elements[i].getRow() == ((ArraySparseMatrix) other).elements[j].getRow()) && (this.elements[i].getCol() == ((ArraySparseMatrix) other).elements[j].getCol())) {
                    int r = ((ArraySparseMatrix) other).elements[j].getRow();
                    int c = ((ArraySparseMatrix) other).elements[j].getCol();
                    double v = ((ArraySparseMatrix) other).elements[j].getValue() + this.elements[i].getValue();
                    matrix2.put(new Entry(r, c, v));
                    i++;
                    count++;
                }
            }
            break;
        }
        for(i=i;i<this.elemCount;i++){
            int r = this.elements[i].getRow();
            int c = this.elements[i].getCol();
            double v = this.elements[i].getValue();
            matrix2.put(new Entry(r, c, v));
            count++;
        }
        for(j=j;j<other.getElemCount();j++){
            int r = ((ArraySparseMatrix) other).elements[j].getRow();
            int c = ((ArraySparseMatrix) other).elements[j].getCol();
            double v = ((ArraySparseMatrix) other).elements[j].getValue();
            matrix2.put(new Entry(r, c, v));
            count++;
        }
        matrix2.elemCount=count;
    	return matrix2;
    }

    public Entry[] getElements() {
        return elements;
    }

    @Override
    public SparseMatrix multiply(SparseMatrix aMatrix) {
        throw new IllegalStateException("Not implemented");
    }

    @Override
    public int getRowCount() {
        return rowCount;
    }

    @Override
    public int getColumnCount() {
        return columnCount;
    }

    @Override
    public int getElemCount() {
        return elemCount;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof ArraySparseMatrix)) return false;
        ArraySparseMatrix other = (ArraySparseMatrix) obj;

        if (rowCount != other.rowCount || columnCount != other.columnCount || elemCount != other.elemCount)
            return false;

        for (int i = 0; i < elements.length; i++) {
            if (!elements[i].equals(other.elements[i])) return false;
        }
        return true;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append(rowCount + "\t" + columnCount + "\t" + elemCount + "\n");
        for (int i = 0; i < elemCount; i ++)
            builder.append(elements[i] + "\n");

        return builder.toString();
    }
}
