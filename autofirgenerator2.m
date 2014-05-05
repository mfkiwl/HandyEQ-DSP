%AUTOFIR VERSION 2 - Multiple coefficient sets
%Generate FIR filter coefficents, VHDL package file.
%Frequency and step response saved to .png files.
%Coefficents in the VHDL file is fractional binary format
%Preben Thor�d and Jonas Hemlin - Chalmers - MPEES1 2013

%%%%%%%%%%%%%% Spec %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
generate_png = 0; 
generate_vhd = 0;
calculate_fir = 0;
calculate_multiple_fir = 1;
generate_test = 1;

autofir_fs = 120000;    %sample rate (hz)
autofir_fc = [15000 40 30000];     %cutoff frequency (hz)
autofir_N = 3;         %filter order (N+1 filter coefficients)

autofir_wordlength = 12;
autofir_fractions = 11; 
autofir_integers = autofir_wordlength - autofir_fractions; 
autofir_signed = 1;     %1=signed 0=unsigned

%%%%%%%%%%%%%%%%%%MULTIARRAY STUFF%%%%%%%%%%%%%%
[~,nfilters] = size(autofir_fc)
if generate_test
    fileID2 = fopen('arraytest.vhd','w');
    fprintf(fileID2,'-- Number of filter sets: \n');
    fprintf(fileID2,'\n');
    fprintf(fileID2,'%d\n', nfilters);
    
    fprintf(fileID2,'\n');
    %array, number of coeff:
    for j = 1:autofir_N+1
        %pr line, x nfilters
        for i = 1:nfilters
            fprintf(fileID2, '()');
        end
        fprintf(fileID2, '\n');
    end
    fclose(fileID2);
end



%%%%%%%%%%%%%% Calculate MULTIPLE SET FIR coefficients %%%%%%%%%%%%%%%%%
if (calculate_multiple_fir)
autofir_fc_norm = autofir_fc / (autofir_fs/2);
autofir_coeff_double = fir1(autofir_N, autofir_fc_norm); %FIR
end
%Convert to fractional binary representation (string)
autofir_coeff_fracbin = cell(1,autofir_N+1); 
for i = 1:autofir_N+1       
   %autofir_coeff_fracbin{1,i} = bin(fi(autofir_coeff_double(i),1,16,15));   
   autofir_coeff_fracbin{1,i} = bin(fi(autofir_coeff_double(i),autofir_signed,autofir_wordlength,autofir_fractions));   
end

%%%%%%%%%%%%%% Calculate FIR coefficients %%%%%%%%%%%%%%%%%
if (calculate_fir)
autofir_fc_norm = autofir_fc / (autofir_fs/2);
autofir_coeff_double = fir1(autofir_N, autofir_fc_norm); %FIR
end
%Convert to fractional binary representation (string)
autofir_coeff_fracbin = cell(1,autofir_N+1); 
for i = 1:autofir_N+1       
   %autofir_coeff_fracbin{1,i} = bin(fi(autofir_coeff_double(i),1,16,15));   
   autofir_coeff_fracbin{1,i} = bin(fi(autofir_coeff_double(i),autofir_signed,autofir_wordlength,autofir_fractions));   
end

%%%%%%%%%%%%%% Plot filters and save to images %%%%%%%%%%%%
if (generate_png)
h=fvtool(autofir_coeff_double, 'Fs', autofir_fs);
writetime =datestr(now,'yyddmm-HHMM');
set(h,'Analysis','magnitude')
%saveas(gcf, strcat(datestr(now,'yyddmm-HHMMSS'),'-freq'),'png');
%saveas(gcf, strcat(writetime,'N',autofir_N,'fc',autofir_fc,'-freq'),'png');
saveas(gcf, strcat(writetime,'jabba','-freq'),'png');
set(h,'Analysis','step')
%saveas(gcf, strcat(datestr(now,'yyddmm-HHMMSS'),'-step'),'png');
%saveas(gcf, strcat(writetime,'N',autofir_N,'fc',autofir_fc,'-step'),'png');
end

%%%%%%%%%%%%%% VHDL file generation %%%%%%%%%%%%%%%%%%%%%%%
if generate_vhd
fileID = fopen('autofir2.vhd','w');

%Header
fprintf(fileID,'-- autofir.vhd\n');
fprintf(fileID,'-- VHDL package holding LP FIR filter coefficients\n');
fprintf(fileID,'-- Preben Thor�d and Jonas Hemlin - Chalmers - MPEES1\n\n');

fprintf(fileID,'-- Autogenerated file. Generated by "autofirgenerator.m"\n');
fprintf(fileID,'-- Generated: ');
fprintf(fileID,'                  ');
fprintf(fileID,datestr(now,'dd mmmm yyyy HH:MM:SS\n'));
fprintf(fileID,'-- Filter order (N)             %d\n',autofir_N);
fprintf(fileID,'-- Sample frequency (fs)        %dHz : \n',autofir_fs);
fprintf(fileID,'-- Cutoff frequency (fc)        %dHz : \n',autofir_fc);
fprintf(fileID,'-- Fractional binary format:    %d.%d \n\n', autofir_integers,autofir_fractions);
%Library
fprintf(fileID,'library ieee;\n');
fprintf(fileID,'use ieee.std_logic_1164.all; \n\n');
%Package
fprintf(fileID,'package autofir_pkg is  \n');
fprintf(fileID,'\tconstant N : integer :=%d; \n',autofir_N);
fprintf(fileID,'\tconstant WIDTH: integer :=%d; \n',autofir_wordlength);
fprintf(fileID,'\ttype filter_coeff_array IS ARRAY (0 to N) of std_logic_vector(WIDTH-1 DOWNTO 0); \n');
    %filter coefficients:
    fprintf(fileID,'\tconstant t : filter_coeff_array :=( \n');
    for i = 1:autofir_N
    fprintf(fileID,'\t\t\t\t\t"%s", -- b%d: \t\t%g \n',autofir_coeff_fracbin{1,i},i-1,autofir_coeff_double(i));
    end
    fprintf(fileID,'\t\t\t\t\t"%s"  -- b%d: \t\t%g \n',autofir_coeff_fracbin{1,autofir_N+1},autofir_N+1-1,autofir_coeff_double(autofir_N+1));
    fprintf(fileID,'\t\t\t\t\t); \n');

fprintf(fileID,'end autofir_pkg; \n\n');

fprintf(fileID,' \n');

fclose(fileID);
end