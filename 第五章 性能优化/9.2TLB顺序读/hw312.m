x = 10:22;
a = load('7-1.txt');

b = load('7-2.txt');

plot(x, a, '-*r', x, b, '-sb')
legend('按行存，改进前','改进后')
set(gca,'xtick',10:24);
set(gca,'xticklabel',{'2^{10}', '', '2^{12}', '', '2^{14}', '', '2^{16}', '', '2^{18}', '', '2^{20}' '', '2^{22}'});
xlabel('Working Set Size(Bytes)');
ylabel('Cycles/List Element');
title('TLB对顺序读的影响');
grid on