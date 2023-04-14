void diskastra(int graph[v][v] , int src){
    int dis[V]; 
    bool Set[v]; 
    

    // initially sabko ste kr fiya
    for(int i=0;i<V;I++){
        dis[i]=INT_MAX,Set[i]=false;
    }

    // because src ki duri khud se zero hi hogi
    dis[src]=0; 

    // hr path ka sortest distance find krenge 

    for(int i=0;i<V;i++){
        int u = minDistance(dist,Set);// us minimum ka index dega

        Set[u]=true;
        
        for(int u=0;u<V;u++){
            if(!Set[u] && graph[u][v] && dis[u]!=INT_MAX && dis[u] + graph[u][v] < dis[v]){
                dis[v]=dis[u] + graph[u][v];
            }
        }
    }

}