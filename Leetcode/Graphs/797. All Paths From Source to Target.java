class Solution {
    List <List <Integer>> Answer = new ArrayList();
    List <Integer> Path = new ArrayList();
    public void GetAllPaths (int[][] graph, int Source, int Destination) {
        if (Source == Destination) Answer.add(new ArrayList(Path));
        else {
            int N = graph[Source].length;
            for (int i = 0; i < N; i++) {
                Path.add(graph[Source][i]);
                GetAllPaths (graph, graph[Source][i], Destination);
                Path.remove(Path.size() - 1);
            }
        }
    }
    public List <List <Integer>> allPathsSourceTarget(int[][] graph) {
        int N = graph.length;
        Path.add(0);
        GetAllPaths (graph, 0, N - 1);
        return Answer;
    }
}