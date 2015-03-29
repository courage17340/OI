var
a:array[1..300,1..300] of longint;
n,m,k,L:longint;
p:array[1..10000,1..10000]of char;
procedure init;
var
  i,j:longint;
begin
  fillchar(a,sizeof(a),0);
  readln(m,n);
  for i:=1 to m do
    for j:=1 to n do
      read(a[m+1-i,j]);
  k:=0;
  L:=0;
  for i:=1 to m do
    for j:=1 to n do
      begin
        if 2*i+4*j+1>L then L:=2*i+4*j+1;
        if 2*i+3*a[i,j]+1>k then k:=2*i+3*a[i,j]+1;
      end;
  for i:=1 to k do
    for j:=1 to L do
      p[i,j]:='.';
end;
procedure work;
var
  i,j,k1,x,y:longint;
begin
  for i:=m downto 1 do
    for j:=1 to n do
      for k1:=1 to a[i,j] do
        begin
          x:=2*i+3*k1-4;
          y:=2*i+4*j-5;
          p[x,y]:='+';
          p[x,y+1]:='-';
          p[x,y+2]:='-';
          p[x,y+3]:='-';
          p[x,y+4]:='+';
          p[x+1,y]:='|';
          p[x+1,y+1]:=' ';
          p[x+1,y+2]:=' ';
          p[x+1,y+3]:=' ';
          p[x+1,y+4]:='|';
          p[x+1,y+5]:='/';
          p[x+2,y]:='|';
          p[x+2,y+1]:=' ';
          p[x+2,y+2]:=' ';
          p[x+2,y+3]:=' ';
          p[x+2,y+4]:='|';
          p[x+2,y+5]:=' ';
          p[x+2,y+6]:='+';
          p[x+3,y]:='+';
          p[x+3,y+1]:='-';
          p[x+3,y+2]:='-';
          p[x+3,y+3]:='-';
          p[x+3,y+4]:='+';
          p[x+3,y+5]:=' ';
          p[x+3,y+6]:='|';
          p[x+4,y+1]:='/';
          p[x+4,y+2]:=' ';
          p[x+4,y+3]:=' ';
          p[x+4,y+4]:=' ';
          p[x+4,y+5]:='/';
          p[x+4,y+6]:='|';
          p[x+5,y+2]:='+';
          p[x+5,y+3]:='-';
          p[x+5,y+4]:='-';
          p[x+5,y+5]:='-';
          p[x+5,y+6]:='+';
        end;
  for i:=k downto 1 do
    begin
      for j:=1 to L do
        write(p[i,j]);
        writeln;
     end;
end;
begin
  init;
  work;
end.