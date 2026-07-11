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
load('./Config.mat')
open_system("./Model/ACC.slx");