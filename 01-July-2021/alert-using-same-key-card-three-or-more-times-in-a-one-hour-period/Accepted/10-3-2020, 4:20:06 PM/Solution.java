// https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period

class Solution {
    public List<String> alertNames(String[] keyName, String[] keyTime) {
        int n = keyName.length;
        Log[] logs = new Log[n];
        for (int i = 0; i < n; i++) {
            logs[i] = new Log(i, keyName[i], keyTime[i]);
        }
        Arrays.sort(logs);
        HashMap<String, Deque<Long>> seen = new HashMap<>();
        HashSet<String> selected = new HashSet<>();
        for (Log log : logs) {
            if (selected.contains(log.name)) continue;
            if (!seen.containsKey(log.name)) seen.put(log.name, new ArrayDeque<>());
            Deque<Long> prevs = seen.get(log.name);
            while (!prevs.isEmpty() && log.time - prevs.peekFirst() > 60) prevs.pollFirst();
            prevs.addLast(log.time);
            if (prevs.size() >= 3) selected.add(log.name);
        }

        List<String> res = new ArrayList<>(selected);
        Collections.sort(res);
        return res;
    }


    class Log implements Comparable<Log> {
        long min;
        long hour;
        long time;

        String name;
        int idx;

        Log(int idx, String name, String timestamp) {
            this.idx = idx;
            this.name = name;
            String[] split = timestamp.split(":");
            this.hour = Long.parseLong(split[0]);
            this.min = Long.parseLong(split[1]);
            this.time = hour * 60 + min;
        }

        @Override
        public int compareTo(Log o) {
            if (this.time == o.time)
                return Integer.compare(this.idx, o.idx);
            return Long.compare(this.time, o.time);
        }

        @Override
        public String toString() {
            return "(" + name + "; " + idx + ":" + time + ")";
        }
    }
}