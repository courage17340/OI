var
  n,x1,y1,g,k,i,x,y,ans:longint;
  a:array[1..100000,1..4] of longint;
begin
  read(n);
  for i:=1 to n do
    begin
      read(a[i,1],a[i,2],x1,y1);
      a[i,3]:=a[i,1]+x1;a[i,4]:=a[i,2]+y1;
    end;
  read(x,y);
  ans:=-1;
  for i:=n downto 1 do
    if (x>=a[i,1])and(x<=a[i,3])and(y>=a[i,2])and(y<=a[i,4]) then
      begin ans:=i;break;end;
  writeln(ans);
end.