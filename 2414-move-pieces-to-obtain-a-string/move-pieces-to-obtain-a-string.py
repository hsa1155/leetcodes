class Solution:
    def canChange(self, start: str, target: str) -> bool:
        len_st,len_tar=len(start),len(target)
        st_index=0
        tar_index=0

        if(len_st!=len_tar):
            return False
        
        while tar_index<len_tar or st_index<len_st:
            while tar_index<len_tar:
                if target[tar_index] != '_':
                    break
                tar_index+=1

            while st_index<len_st:
                if start[st_index] != '_':
                    break
                st_index+=1
            
            #if one to the end another must be end too
            if st_index==len_st or tar_index==len_tar:
                if st_index^tar_index!=0:
                    return False
                else:
                    break
            
            if (
                start[st_index] != target[tar_index] # no match l r
                or (start[st_index] == "L" and st_index < tar_index)
                or (start[st_index] == "R" and st_index > tar_index)
            ):
                return False
            st_index += 1
            tar_index += 1


        return True
            
                    
