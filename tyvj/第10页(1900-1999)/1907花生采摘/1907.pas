var
  p:array[0..20,0..20] of longint;
  m,n,k,t,count:longint;
procedure init;
var
  i,j:longint;
begin
  readln(m,n,k);
  fillchar(p,sizeof(p),0);
  for i:=1 to m do
    begin
      for j:=1 to n do read(p[i,j]);
      readln;
    end;
end;
procedure work;
var
  x,y,x1,y1,s,i,j:longint;
begin
  x:=0;
  y:=0;
  x1:=0;
  y1:=0;
  t:=0;
  s:=0;
  count:=0;
  while t<k do
    begin
      for i:=1 to m do
        for j:=1 to n do
          if s<p[i,j] then
            begin
              x1:=i;
              y1:=j;
              s:=p[i,j];
            end;
      if x=0
        then
          t:=t+x1+1
        else
          t:=t+abs(x-x1)+abs(y-y1)+1;
      if t+x1>k then break;
      count:=count+s;
      p[x1,y1]:=0;
      x:=x1;
      y:=y1;
      s:=0;
    end;
  write(count);
end;
begin
  init;
  work;
end.