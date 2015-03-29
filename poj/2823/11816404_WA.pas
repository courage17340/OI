var
  a,b,c,f1,f2:array[1..1000000] of longint;
  n,i,j,k,p1,p2,q1,q2:longint;
begin
  readln(n,k);
  for i:=1 to n do read(a[i]);
  p1:=1;
  q1:=1;
  p2:=1;
  q2:=1;
  b[1]:=1;
  c[1]:=1;
  for i:=2 to n do
    begin
      while (q1>=p1)and(a[i]<=a[b[q1]]) do dec(q1);
      inc(q1);
      b[q1]:=i;
      while b[p1]<i-k+1 do inc(p1);
      f1[i]:=a[b[p1]];
      while (q2>=p2)and(a[i]>=a[c[q2]]) do dec(q2);
      inc(q2);
      c[q2]:=i;
      while c[p2]<i-k+1 do inc(p2);
      f2[i]:=a[c[p2]];
    end;
  for i:=k to n-1 do write(f1[i],' ');
  writeln(f1[n]);
  for i:=k to n-1 do write(f2[i],' ');
  writeln(f2[n]);
end.