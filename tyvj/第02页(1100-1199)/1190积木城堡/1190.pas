var
  a:array[0..100,0..100] of longint;
  b:array[0..100,0..10000] of 0..1;
  l,h:array[0..100] of longint;
  min,x,n:longint;
procedure init;
var
  i:longint;
begin
  readln(n);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(l,sizeof(l),0);
  fillchar(h,sizeof(h),0);
  for i:=1 to n do
    begin
      read(x);
      while x<>-1 do
        begin
          l[i]:=l[i]+1;
          a[i,l[i]]:=x;
          h[i]:=h[i]+x;
          read(x);
        end;
      readln;
    end;
  min:=maxlongint;
  for i:=1 to n do if min>h[i] then min:=h[i];
end;
procedure print;
begin
  writeln(x);
end;
procedure find;
var
  i,j:longint;
  t:boolean;
begin
  for i:=min downto 1 do
    begin
      t:=true;
      for j:=1 to n do if b[j,i]=0 then t:=false;
      if t then
        begin
          x:=i;
          print;
          halt;
        end;
    end;
  writeln(0);
end;
procedure work;
var
  i,j,k:longint;
begin
  init;
  for i:=1 to n do b[i,0]:=1;
  for i:=1 to n do
    for j:= 1 to l[i] do
      for k:=min downto a[i,j] do
        if b[i,k-a[i,j]]=1 then b[i,k]:=1;
  find;
end;
begin
  work;
end.