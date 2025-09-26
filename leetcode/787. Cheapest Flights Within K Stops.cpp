class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Pirmiausia paverciame i iprasta graph formata

        vector<vector<pair<int, int>>> graph(n); // i kur (kaimynas) ir keliones kaina
        // graph leidzia suzinoti miesto numeri, kaimyna ir kaina tarp ju

        for(auto &flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        // formatas
        // 0 indeksas turi masyva, kuriame yra kiti masyvai. Kiekvienas is ju turi kaimynini nari ir kaina

        // Iprastai priority_queue<tuple<int, int, int>> rikiuotu didejimo tvarka
        // Pirmas butu didziausias
        // Taciau kad butu pirmas maziausias, reikia prideti vector<tuple<int, int, int>>, greater<tuple<int, int, int>>

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> q;

        q.push({0, src, 0}); // {kaina_dabartine, dab, sustojimai_dabartinio}

        vector<vector<int>> minKaina(n, vector<int>(k+2, INT_MAX));
        minKaina[src][0] = 0;

        int res=INT_MAX;

        while(!q.empty()) {
            auto [kaina_dabartine, dab, sustojimai_dabartinio] = q.top(); // sustojimai tai nodes tarp src ir dst
            q.pop();

            if(dab == dst) return kaina_dabartine; // pasiekeme galutini ta, graziname kaina

            if(sustojimai_dabartinio > k) continue; // jei virsytas maksimalus sustojimu skaicius

            for(auto &[to, kaina] : graph[dab]) {
                int busima_kaina = kaina_dabartine + kaina;
                int kita = sustojimai_dabartinio + 1;

                if(busima_kaina < minKaina[to][kita]) {
                    minKaina[to][kita] = busima_kaina;
                    q.push({busima_kaina, to, kita});
                }
            }
        }

        return -1; // jei negalima pasiekti
    }
};
