���ߣ�Java3y
���ӣ�https://zhuanlan.zhihu.com/p/34982598
��Դ��֪��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������

public static void main(String[] args) {

        int[] arrays = {6, 4322, 432, 344, 55, 234, 45, 243, 5, 2, 4, 5, 6, 7, 3245, 345, 345, 234, 68, 65};

        radixSort(arrays);

        System.out.println("���ںţ�Java3y" + arrays);

    }

    public static void radixSort(int[] arrays) {

        int max = findMax(arrays, 0, arrays.length - 1);

        //��Ҫ�����Ĵ������������ֵ��λ��������
        for (int i = 1; max / i > 0; i = i * 10) {

            int[][] buckets = new int[arrays.length][10];

            //��ȡÿһλ����(����ʮ���١�ǧλ...���䵽Ͱ����)
            for (int j = 0; j < arrays.length; j++) {

                int num = (arrays[j] / i) % 10;

                //�������Ͱ����
                buckets[j][num] = arrays[j];
            }

            //����Ͱ�����Ԫ��
            int k = 0;

            //��10��Ͱ��
            for (int j = 0; j < 10; j++) {
                //��ÿ��Ͱ�����Ԫ�ؽ��л���
                for (int l = 0; l < arrays.length ; l++) {

                    //���Ͱ��������Ԫ�ؾͻ���(���ݳ�ʼ����Ϊ0)
                    if (buckets[l][j] != 0) {
                        arrays[k++] = buckets[l][j];

                    }

                }

            }

        }
    }


    /**
     * �ݹ飬�ҳ���������ֵ
     *
     * @param arrays ����
     * @param L      ��߽磬��һ����
     * @param R      �ұ߽磬����ĳ���
     * @return
     */

    public static int findMax(int[] arrays, int L, int R) {

        //���������ֻ��һ��������ô���ľ��Ǹ������һ��ֵ��
        if (L == R) {
            return arrays[L];
        } else {

            int a = arrays[L];
            int b = findMax(arrays, L + 1, R);//�ҳ���������ֵ

            if (a > b) {
                return a;
            } else {
                return b;
            }
        }
    }
