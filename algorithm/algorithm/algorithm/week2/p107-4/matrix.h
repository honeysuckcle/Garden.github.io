#pragma once
class SparseMatrix {
public:
	SparseMatrix();
	SparseMatrix Transpose();
private:
	int Rows, Cols,Terms;
	MatrixTerm smArray[5];
};

class MatrixTerm {
	friend SparseMatrix;
private:
	int row, col, value;
};


SparseMatrix SparseMatrix::Transpose() {
	int *RowStart = new int[Cols];

	SparseMatrix b;
	b.Rows = Cols;
	b.Cols = Rows;
	b.Terms = Terms;
	if (Terms > 0) 
	{
		RowStart[0] = 0;
		for(int i = 1;i < Cols;i++)
		{
			int size = 0;
			for (int j = 0; j < Terms; j++)
			{
				if ((i-1) == smArray[j].col)
					size++;
			}
			RowStart[i] = RowStart[i - 1] + size;
		}

		for (int i = 0; i < Terms; i++)
		{
			int j = RowStart[smArray[i].col];
			b.smArray[j].row = smArray[i].col;
			b.smArray[j].col = smArray[i].row;
			b.smArray[j].value = smArray[i].value;
			RowStart[smArray[i].col]++;
			//确定在哪个位置填值
		}
	}

}