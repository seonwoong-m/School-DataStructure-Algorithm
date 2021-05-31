#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<stdio.h>

class MazeGenerator {

	static const int LOAD = 1;
	static const int BLOCK = 0;
	struct Node {
		int i, j;
		int k;
		Node() { i = j = 0; k = -1; }
		Node(int _i, int _j) { i = _i; j = _j; k = -1; }
		Node(int _i, int _j, int _k) { i = _i; j = _j; k = _k; }
	};
	__inline int _data_id(int i, int j) { return i * tw + j; }
	__inline int _node_id(int i, int j) { return i * w + j; }
	__inline int _node_id(Node node) { return node.i * w + node.j; }
	void inil()
	{
		map.resize(th * tw);

		int i, j;
		for (i = 0; i < th; i++)
			for (j = 0; j < tw; j++)
			{
				map[_data_id(i, j)] = BLOCK;
			}
		do {
			switch (type)
			{
			case MGT_WITHOUT_BOUNDARY:
				si = (rand() % h);
				sj = (rand() % w);
				ei = (rand() % h);
				ej = (rand() % w);
				break;
			case MGT_WITHOUT_WALL:
				if (rand() % 2 == 0)
				{
					si = (rand() % h) + 1;
					sj = (rand() % 2) * (w + 1);
				}
				else
				{
					si = (rand() % 2) * (h + 1);
					sj = (rand() % w) + 1;
				}
				if (rand() % 2 == 0)
				{
					ei = (rand() % h) + 1;
					ej = (rand() % 2) * (w + 1);
				}
				else
				{
					ei = (rand() % 2) * (h + 1);
					ej = (rand() % w) + 1;
				}
				break;
			case MGT_WITH_WALL:
				if (rand() % 2 == 0)
				{
					si = (rand() % h) * 2 + 1;
					sj = (rand() % 2) * (2 * w);
				}
				else
				{
					si = (rand() % 2) * (2 * h);
					sj = (rand() % w) * 2 + 1;
				}
				if (rand() % 2 == 0)
				{
					ei = (rand() % h) * 2 + 1;
					ej = (rand() % 2) * (2 * w);
				}
				else
				{
					ei = (rand() % 2) * (2 * h);
					ej = (rand() % w) * 2 + 1;
				}
				break;
			}
		} while (std::abs(si - ei) + std::abs(sj - ej) <= 2);
	}
	bool _generate()
	{
		int i, j, k;
		int di[4] = { 0,1,0,-1 };
		int dj[4] = { 1,0,-1,0 };

		std::vector<Node> bfs;
		std::vector<int> mark;
		std::vector<int> dist;
		Node node_s;
		Node node_e;

		int q, r;
		mark.resize(w * h);
		dist.resize(w * h);
		bfs.resize(w * h);
		{
			for (i = 0; i < w * h; i++)
				mark[i] = dist[i] = 0;
		} // clear memory
		{
			map[_data_id(si, sj)] = LOAD;
			map[_data_id(ei, ej)] = LOAD;

			if (si == 0) {
				switch (type) {
				case MGT_WITHOUT_BOUNDARY: node_s = Node(si, sj, 1); break;
				case MGT_WITHOUT_WALL: node_s = Node(0, sj - 1, 1); break;
				case MGT_WITH_WALL: node_s = Node(0, sj / 2, 1); break;
				};
			}
			else if (si == th - 1) {
				switch (type) {
				case MGT_WITHOUT_BOUNDARY: node_s = Node(si, sj, 3); break;
				case MGT_WITHOUT_WALL: node_s = Node(h - 1, sj - 1, 3); break;
				case MGT_WITH_WALL: node_s = Node(h - 1, sj / 2, 3); break;
				};
			}
			else if (sj == 0) {
				switch (type) {
				case MGT_WITHOUT_BOUNDARY: node_s = Node(si, sj, 0); break;
				case MGT_WITHOUT_WALL: node_s = Node(si - 1, 0, 0); break;
				case MGT_WITH_WALL: node_s = Node(si / 2, 0, 0); break;
				};
			}
			else {
				switch (type) {
				case MGT_WITHOUT_BOUNDARY: node_s = Node(si, sj, 2); break;
				case MGT_WITHOUT_WALL: node_s = Node(si - 1, w - 1, 2); break;
				case MGT_WITH_WALL: node_s = Node(si / 2, w - 1, 2); break;
				};
			}

			if (ei == 0) {
				switch (type) {
				case MGT_WITHOUT_BOUNDARY: node_e = Node(ei, ej, 1); break;
				case MGT_WITHOUT_WALL: node_e = Node(0, ej - 1, 1); break;
				case MGT_WITH_WALL: node_e = Node(0, ej / 2, 1); break;
				};
			}
			else if (ei == th - 1) {
				switch (type) {
				case MGT_WITHOUT_BOUNDARY: node_e = Node(ei, ej, 3); break;
				case MGT_WITHOUT_WALL: node_e = Node(h - 1, ej - 1, 3); break;
				case MGT_WITH_WALL: node_e = Node(h - 1, ej / 2, 3); break;
				};
			}
			else if (ej == 0) {
				switch (type) {
				case MGT_WITHOUT_BOUNDARY: node_e = Node(ei, ej, 0); break;
				case MGT_WITHOUT_WALL: node_e = Node(ei - 1, 0, 0); break;
				case MGT_WITH_WALL: node_e = Node(ei / 2, 0, 0); break;
				};
			}
			else {
				switch (type) {
				case MGT_WITHOUT_BOUNDARY: node_e = Node(ei, ej, 2); break;
				case MGT_WITHOUT_WALL: node_e = Node(ei - 1, w - 1, 2); break;
				case MGT_WITH_WALL: node_e = Node(ei / 2, w - 1, 2); break;
				};
			}

			q = 0; r = 1;
			bfs[q] = node_s;
			mark[_node_id(node_s)] = 1;
			dist[_node_id(node_s)] = 1;
		}// init bfs done
		{
			while (q < r)
			{
				//rand select;
				{
					int ri = rand() % (r - q) + q;
					std::swap(bfs[q], bfs[ri]);
					std::swap(mark[_node_id(bfs[q])], mark[_node_id(bfs[ri])]);
				}
				Node qq = bfs[q];

				if (type == MGT_WITHOUT_BOUNDARY || type == MGT_WITHOUT_WALL)
				{
					int cnt = 0;
					for (k = 0; k < 4; k++)
					{
						Node tq(qq.i + di[k], qq.j + dj[k], k);
						if (tq.i >= 0 && tq.i < h)
							if (tq.j >= 0 && tq.j < w)
								if (mark[_node_id(tq)] < 0)
									cnt++;
					}
					if (cnt > 1)
					{
						q++;
						continue;
					}
				}

				if (qq.i == node_e.i && qq.j == node_e.j && dist[_node_id(qq)] < MIN_DIST) {
					if (r == q + 1)
						return false;
					continue;
				}
				mark[_node_id(qq)] = -1;
				// backward
				{
					int ti, tj, tk;

					switch (type) {
					case MGT_WITHOUT_BOUNDARY:	ti = qq.i; tj = qq.j; break;
					case MGT_WITHOUT_WALL:		ti = qq.i + 1; tj = qq.j + 1; break;
					case MGT_WITH_WALL:			ti = qq.i * 2 + 1; tj = qq.j * 2 + 1; break;
					};
					map[_data_id(ti, tj)] = LOAD;
					if (type == MGT_WITH_WALL)
					{
						tk = (qq.k + 2) % 4;
						map[_data_id(ti + di[tk], tj + dj[tk])] = LOAD;
					}
				}
				// go away, anna
				for (k = 0; k < 4; k++)
				{
					Node tq(qq.i + di[k], qq.j + dj[k], k);
					if (tq.i >= 0 && tq.i < h)
						if (tq.j >= 0 && tq.j < w)
							if (mark[_node_id(tq)] >= 0)
							{
								if (mark[_node_id(tq)] == 0)
								{
									mark[_node_id(tq)] = r + 1;
									bfs[r] = tq;
									dist[_node_id(tq)] = dist[_node_id(qq)] + 1;
									r++;
								}
								else
								{
									int ri = mark[_node_id(tq)] - 1;
									bfs[ri].k = tq.k;
									dist[_node_id(tq)] = dist[_node_id(qq)] + 1;
								}
							}
				}
				q++;
			}
		}// generate done
		if (mark[_node_id(node_e)] >= 0) return false;
		printf("dist : %d\n", dist[_node_id(node_e)]);
		return true;
	}
public:
	enum MAZE_GENERATE_TYPE {
		MGT_WITHOUT_BOUNDARY,	// return (w)*(h) map. 
		MGT_WITHOUT_WALL,		// return (w+2)*(h+2) map.
		MGT_WITH_WALL,			// return (2*w+1)*(2*h+1) map.
	};
	int MIN_DIST;
	int w, h;
	int tw, th;
	std::vector<int> map;
	int seed;
	MAZE_GENERATE_TYPE type;

	int si, sj;
	int ei, ej;

	void MazeGenerator()
	{
		w = 3; h = 3;
		seed = 0;
		MIN_DIST = -1;
		type = MGT_WITHOUT_BOUNDARY;
	}
	void MazeGenerator(int width, int height)
	{
		w = width; h = height;
		seed = 0;
		MIN_DIST = -1;
		type = MGT_WITHOUT_BOUNDARY;
	}
	void MazeGenerator(int width, int height, int _seed)
	{
		w = width; h = height; seed = _seed;
		MIN_DIST = -1;
		type = MGT_WITHOUT_BOUNDARY;
	}
	void bind()
	{
		srand(seed);
		switch (type)
		{
		case MGT_WITHOUT_BOUNDARY:
			th = h;
			tw = w;
			break;
		case MGT_WITHOUT_WALL:
			th = h + 2;
			tw = w + 2;
			break;
		case MGT_WITH_WALL:
			th = 2 * h + 1;
			tw = 2 * w + 1;
			break;
		}
		if (MIN_DIST < 0)
			MIN_DIST = (w + h);
	}
	void generate()
	{
		int trial = 0;
		do {
			trial++;
			printf("%d's try\n", trial);
			inil();
			if (trial % 5 == 0) { MIN_DIST--; if (MIN_DIST < 0) break; printf("Minimum_dist decrease --> %d\n", MIN_DIST); }
		} while (!_generate());
		if (MIN_DIST < 0)
			printf("do dive!\n");
	}
	void print()
	{
		int i, j;
		printf("width : %d, height : %d, MIN_DIST : %d\n", w, h, MIN_DIST);
		for (i = 0; i < th; i++, printf("\n"))
			for (j = 0; j < tw; j++)
			{
				if (i == si && j == sj)
					printf("s");
				else if (i == ei && j == ej)
					printf("e");
				else
					printf("%d", map[_data_id(i, j)]);
			}
	}
};

int main()
{
	// map size == th * tw
	//
	MazeGenerator maze;

	maze.w = 10;
	maze.h = 10;
	maze.seed = 70;
	maze.type = MazeGenerator::MGT_WITHOUT_BOUNDARY;

	maze.bind();
	maze.generate();

	maze.print();
	return 0;
}