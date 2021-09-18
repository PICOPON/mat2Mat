Mat readInToMatrix(string FilePath)
{
	fstream file;
	file.open(FilePath, ios::in);//打开一个file
	assert(file.is_open());
	string buff;
	vector<vector<double>> data;
	int cols, rows;
	int i = 0;
	while (getline(file, buff)) {
		vector<double> nums;
		// string->char *
		char* s_input = (char*)buff.c_str();
		const char* split = ",";
		// 以‘,’为分隔符拆分字符串
		char* p = strtok(s_input, split);
		double a;
		while (p != NULL) {
			// char * -> int
			a = atof(p);
			//cout << a << endl;
			nums.push_back(a);
			p = strtok(NULL, split);
		}
		cols = nums.size();
		data.push_back(nums);
		i++;
	}
	rows = data.size();
	Mat mat = Mat::zeros(Size(cols, rows), CV_32FC1);
	for (int i = 0; i < rows;i++) {
		for (int j = 0; j < cols;j++) {
			mat.at<float>(i, j) = data[i][j];
		}
	}
	file.close();
	return mat;
}
