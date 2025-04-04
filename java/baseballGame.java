class Solution {
    public int calPoints(String[] operations) {
        List<Integer> record = new ArrayList();
        int pointer = 0;
        int total = 0;
        for (String operation : operations) {
            if ("+".equals(operation)) {
                int result = record.get(pointer-1) + record.get(pointer-2);
                total += result;
                record.add(result);
                pointer++;
            } else if ("D".equals(operation)) {
                int result = record.get(pointer-1) * 2;
                total += result;
                record.add(result);
                pointer++;
            } else if ("C".equals(operation)) {
                total -= record.get(pointer-1);
                record.remove(pointer-1);
                pointer--;
            } else {
                total += Integer.parseInt(operation);
                record.add(Integer.parseInt(operation));
                pointer++;
            }
        }
        return total;

    }
}
