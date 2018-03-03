x=[1:1:5];
a=[0.006,
0.015,
0.035,
0.047,
0.113,
];
b=[0.003,
0.013,
0.032,
0.043,
0.099,
];

plot(x,a,'-*r',x,b,'-sb');

axis([1,8,0,0.13])
set(gca,'XTickLabel',{'1024*768','','2048*1096','','2560*1920','','3000*2000','','4000*3000',''})
set(gca,'YTick',[0:0.01:0.13]) %改变y轴坐标间隔显示
xlabel('图片大小')
ylabel('Time/s')
legend('按照原图现行后列','按照目的图现行后列');
grid on;