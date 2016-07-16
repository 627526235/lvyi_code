function [aver,var] = get_average_var(path)
%calculate the average and variance throught path
a = importdata(path);
aver = mean(a);
b = std(a);
var = b.^2;
col = size(a,2);
c = sort(a);
file_name = '_result.txt';
fid = fopen(file_name,'wt');
fprintf(fid,'average:\n');
fprintf(fid,'%g\n',aver);
fprintf(fid,'variance:\n');
fprintf(fid,'%g\n',var);
fclose(fid);
% for i=1 : col
%     figure
%     histfit(c(:,i),100)
%     
%     hold on
% end    
for i = 1 : col
    figure(i);
    xmin = min(c(:,i));
    xmax = max(c(:,i));
    xp = linspace(xmin,xmax,70);
    f = ksdensity(c(:,i),xp);
    title_now = strcat('test',num2str(i));
    plot(xp,f),title(title_now);
    print(i,'-dpng',title_now);
    
end    
% for i = 1 :col
%     figure
%     [f,xi] = ksdensity(c(:,i))
%     plot(xi,f,'*')
%     hold on
% end   

   