class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int>adj[numCourses];
         int m = prerequisites.size();
	    // convert the list-pairs into adjacency list
	    for(int i=0;i<m;i++){
	            int x = prerequisites[i][0];
	            int y = prerequisites[i][1];
	            // edge between: y->x
	            adj[y].push_back(x);
	    }
	   vector<int>ans;
	   vector<int>inDegree(numCourses,0); // indegree
	   // for storing the indegree of the vertex
	   for(int i=0;i<numCourses;i++){
	      for(auto it:adj[i]){
	          inDegree[it]++;
	      } 
	   }
	   
	   //now apply bfs
	   queue<int>q;
	   // push all the vertex with inDegree = 0
	   for(int i=0;i<numCourses;i++){
	       if(inDegree[i] == 0){
	           q.push(i);
	       }
	   }
	   while(!q.empty()){
	       int node = q.front();
	       q.pop();
	       
	       // push the node to the answer vector
	       ans.push_back(node);
	       // traverse all the adjacncy nodes
	       for(auto neighbour:adj[node]){
	           inDegree[neighbour]--;
	           if(inDegree[neighbour] == 0){
	               q.push(neighbour);
	           }
	       }
	   }
	   if(ans.size() == numCourses) return true;
	   return false;
    }
};