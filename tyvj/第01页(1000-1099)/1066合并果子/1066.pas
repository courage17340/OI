var
  a:array[0..10000] of longint;
  n,i,j,k,ans:longint;
procedure swap(var a,b:longint);
var t:longint;
begin
  t:=a;a:=b;b:=t;
end;
begin
  readln(n);ans:=0;
  for i:=1 to n do read(a[i]);
  i:=n;
  while i>1 do
    begin
      for j:=i downto i-1 do
        for k:=1 to j-1 do if a[k]<a[k+1] then swap(a[k],a[k+1]);
      a[i-1]:=a[i-1]+a[i];
      dec(i);
      ans:=ans+a[i];
    end;
  writeln(ans);
end.