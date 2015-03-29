var
  s1,s2:array[0..1000] of longint;
  m,n,k,L,d,count:longint;
procedure init;
var
  i,x,y,p,q:longint;
begin
  fillchar(s1,sizeof(s1),0);
  fillchar(s2,sizeof(s2),0);
  readln(m,n,k,L,d);
  for i:=1 to d do
    begin
      readln(x,y,p,q);
      if x=p then
        if y<q then inc(s2[y])
               else inc(s2[q]);
      if y=q then
        if x<p then inc(s1[x])
               else inc(s1[p]);
    end;
end;
procedure work;
var
  i,j,x:longint;
begin
  for i:=1 to k do
    begin
      x:=1;
      for j:=1 to m do
        if s1[j]>s1[x] then x:=j;
      s1[x]:=-1;
    end;
  for i:=1 to L do
    begin
      x:=1;
      for j:=1 to n do
        if s2[j]>s2[x] then x:=j;
      s2[x]:=-1;
    end;
  i:=1;
  while s1[i]<>-1 do inc(i);
  write(i);
  for j:=i+1 to m do
    if s1[j]=-1 then write(' ',j);
  writeln;
  i:=1;
  while s2[i]<>-1 do inc(i);
  write(i);
  for j:=i+1 to n do
    if s2[j]=-1 then write(' ',j);
end;
begin
  init;
  work;
end.