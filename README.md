# FMDataset
We release the dataset called **Fast sensor Motion Dataset**, which is used on our ICME'19 paper. **FMDataset** aims to verify the robustness of Dense-SLAM system at different velocities of sensor motion. 
It contains **color images, depth images and IMUs** gathered by a handheld sensor Intel realsense ZR300. Filtered depth images with better quality are saved in the file "filtered".  
This dataset contains 14 sequences with 6 different scenes. All datasets are divided into slow, medium and fast depending on the camera motion speed and the image blurry degree. To be more specific, as there is no explicit criteria to divide camera speed into slow and fast, thus we empirically set the motion without creating image motion blur as slow camera motion, and the motion which creates severe image blur as fast camera motion.
You may Download our Dataset at:  
**Baidu Drive:** https://pan.baidu.com/s/1g5W1k6vhZM-3JTPQIDmS-A  code: ae79  
**Google Drive:** https://drive.google.com/drive/folders/1oaK3yreUtHjRTx-AVaspcCPGY7YEYBak?usp=sharing

We have also provide **DatasetReader** code for you to easily read our dataset into your project.

# Reference
One of our work has got ICME'19 best student paper award, which proposes a robust real-time reconstruction system under fast sensor motion. You may find our paper and vido below:  
http://39.98.209.108/publications/2019/2019FastFusion.pdf 

http://39.98.209.108/publications/2019/zhuzunjie_VIDEO.mp4

# Citation
If you use FMDataset, please cite our ICME 2019 paper:
```
@inproceedings{Zhu2019,
  title={Real-time Indoor Scene Reconstruction with RGBD and Inertial Input},
  author={Zhu, Zunjie and Xu, Feng and Yan, Chenggang and Hao, Xinhong and Ji, Xiangyang and Zhang, Yongdong and Dai, Qionghai},
  booktitle={Proc. IEEE Int. Conf. Multimedia and Expo (ICME’2019), Shanghai, China},
  year={2019}
}
```
