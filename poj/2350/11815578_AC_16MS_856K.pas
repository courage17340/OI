var
  a:array[1..1000] of longint;
  p,q,x,n,i,j,k,s:longint;
begin
  readln(k);
  for s:=1 to k do
    begin
      read(n);
      for i:=1 to n do read(a[i]);
      readln;
      p:=0;
      for i:=1 to n do inc(p,a[i]);
      q:=n;
      x:=0;
      for i:=1 to n do if a[i]*q>p then inc(x);
      writeln(100*x/n:0:3,'%');
    end;
end.