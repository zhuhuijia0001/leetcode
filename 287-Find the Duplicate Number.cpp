class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        int slow = 0;
        int fast = 0;
        // �ҵ�����ָ�������ĵط�
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
        int find = 0;
        // ��һ����ָ���ͷ��ʼ��ֱ������ָ������
        while(find != slow){
            slow = nums[slow];
            find = nums[find];
        }
        return find;    
    }
};
