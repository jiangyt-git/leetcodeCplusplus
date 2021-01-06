void Dijkstra(int map[][], int u, int m) {
                //输入中map索引横纵都是从1开始，城市编号是从1开始，源地址u可以变化,m个城市，n条边
                const int N = 100; // 初始城市数目
                const int INF = 1e7;
                bool flag[N];
                int dist[N];
                int p[N]; // 记录某个节点最短路径中的前一个节点

                //初始化3个数组,初始时只有一个源点
                flag[u] = true;
                for (int i=1; i <= m; i++){
                    dist[i] = map[u][i];
                    flag[i] = false;
                    // p[] = -1、dist[]=INF 表示源和目的没有连接,
                    if (dist[i] == INF) {
                        p[i] = -1;
                    } else {
                        p[i] = u;
                    }
                }
                dist[u] = 0;
                flag[u] = true;

                // 将剩下的点一个一个的加入S集合，每次选择点都符合贪心选择，即选择一个剩下的点中，dist最短的一个
                for (int i = 1; i <= n; i++) {
                    // 遍历一次，选点
                    int t = u;
                    int min = INF;
                    for (int j = 1; j <= n; j++) {
                        // 非S集合的点
                        if (!flag[j] && dist[j] < INF) {
                            t = j;
                            min = dist[j];
                        }
                    }
                    // 找不到，要么所有的点都加入了，要么剩下的点都不可达，退出
                    if (t == u) {
                        return ;
                    }
                    // 找到了，将该点加入
                    flag[t] = true;
                    // 更新dist，看剩下的点有没有和t点相邻的点，使得某些点可以从借助t点得到最短路径。
                    for (int j = 1; j<=n; j++) {
                        // 非S集合的点  与t相邻
                        if (!flag[j] && map[t][u] < INF) {
                            if (map[t][u] + dist[t] < dist[j]) {
                                dist[j] = map[t][u] + dist[t];
                                p[j] = t;
                            }
                        }
                    }
                }
            }
