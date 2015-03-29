var
  i,n,j,max:longint;
  a,b:array[1..3001] of longint;
  f:array[1..3001] of longint;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
    begin
      max:=0;
      for j:=1 to n do
        begin
          if (a[i]>b[j])and(f[j]>max) then max:=f[j]
           else if (a[i]=b[j])and(f[j]<max+1) then f[j]:=max+1;
        end;
    end;
  max:=0;
  for i:=1 to n do if f[i]>max then max:=f[i];
  writeln(max);
end.