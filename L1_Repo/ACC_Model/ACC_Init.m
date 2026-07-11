clc;
clear all;
clc
% #### Directory Cleanup: ####
try 
    rmdir('slprj','s')
end
delete('*.mexw64');
delete('*.slxc');
close all;
addpath(genpath(pwd));
open_system("./Model/ACC.slx");