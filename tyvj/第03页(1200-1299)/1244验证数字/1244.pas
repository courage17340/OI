type
 arr=array[1..1001,1..2002] of char;
var
 a,b:arr;
 n,i,j,p:longint;
 t:boolean;
function com(a,b:arr):boolean;
var
 i,j:longint;
begin
 for i:=1 to 2*n-1 do
  for j:=1 to n do
   if a[i,j]<>b[i,j] then exit(false);
 exit(true);
end;
procedure draw1;{第一横}
begin
  for j:=1 to n do b[1,j]:='#';
end;
procedure draw2;{第二横}
begin
  for j:=1 to n do b[n,j]:='#';
end;
procedure draw3;{第三横}
begin
  for j:=1 to n do b[2*n-1,j]:='#';
end;
procedure draw4;{左上竖}
begin
  for i:=1 to n do b[i,1]:='#';
end;
procedure draw5;{左下竖}
begin
  for i:=n to 2*n-1 do b[i,1]:='#';
end;
procedure draw6;{右上竖}
begin
  for i:=1 to n do b[i,n]:='#';
end;
procedure draw7;{右下竖}
begin
  for i:=n to 2*n-1 do b[i,n]:='#';
end;
begin
 for p:=1 to 5 do
  begin
   fillchar(a,sizeof(a),'.');
   readln(n);
   for i:=1 to 2*n-1 do
    begin
     for j:=1 to n do read(a[i,j]);
     readln;
    end;
   t:=false;
{0}fillchar(b,sizeof(b),'.');
   draw1;draw3;draw4;draw5;draw6;draw7;
   if com(a,b) then begin t:=true;write(0);end;
{1}if not t then
    begin
     fillchar(b,sizeof(b),'.');
     draw6;draw7;
     if com(a,b) then begin t:=true;write(1);end;
    end;
{2}if not t then
    begin
     fillchar(b,sizeof(b),'.');
     draw1;draw2;draw3;draw5;draw6;
     if com(a,b) then begin t:=true;write(2);end;
    end;
{3}if not t then
    begin
     fillchar(b,sizeof(b),'.');
     draw1;draw2;draw3;draw6;draw7;
     if com(a,b) then begin t:=true;write(3);end;
    end;
{4}if not t then
    begin
     fillchar(b,sizeof(b),'.');
     draw2;draw4;draw6;draw7;
     if com(a,b) then begin t:=true;write(4);end;
    end;
{5}if not t then
    begin
     fillchar(b,sizeof(b),'.');
     draw1;draw2;draw3;draw4;draw7;
     if com(a,b) then begin t:=true;write(5);end;
    end;
{6}if not t then
    begin
     fillchar(b,sizeof(b),'.');
     draw1;draw2;draw3;draw4;draw5;draw7;
     if com(a,b) then begin t:=true;write(6);end;
    end;
{7}if not t then
    begin
     fillchar(b,sizeof(b),'.');
     draw1;draw6;draw7;
     if com(a,b) then begin t:=true;write(7);end;
    end;
{8}if not t then
    begin
     fillchar(b,sizeof(b),'.');
     draw1;draw2;draw3;draw4;draw5;draw6;draw7;
     if com(a,b) then begin t:=true;write(8);end;
    end;
{9}if not t then
    begin
     fillchar(b,sizeof(b),'.');
     draw1;draw2;draw3;draw4;draw6;draw7;
     if com(a,b) then begin t:=true;write(9);end;
    end;
   if not t then write('?');
  end;
  writeln;
end.