var
  f:array[0..6000000] of boolean;
  a:array[0..500000] of longint;
  n,i,x:longint;
begin
  fillchar(f,sizeof(f),0);
  f[0]:=true;
  a[0]:=0;
  for i:=1 to 500000 do
    begin
      if (a[i-1]-i>0)and(not f[a[i-1]-i])
        then a[i]:=a[i-1]-i
        else a[i]:=a[i-1]+i;
      f[a[i]]:=true;
    end;
  while true do
    begin
      readln(x);
      if x=-1 then break;
      writeln(a[x]);
    end;
end.