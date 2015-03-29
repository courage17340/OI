var
  a:array[1..50] of longint;
  n,i,j,s1,s2:longint;
  x:extended;
function gcd(a,b:longint):longint;
begin
  if b=0 then exit(a);
  exit(gcd(b,a mod b));
end;
begin
  while true do
    begin
      readln(n);
      if n=0 then break;
      for i:=1 to n do readln(a[i]);
      s1:=n*(n-1) shr 1;
      s2:=0;
      for i:=1 to n-1 do
        for j:=i+1 to n do
          if gcd(a[i],a[j])=1 then inc(s2);
      if s2=0 then
        begin
          writeln('No estimate for this data set.');
          continue;
        end;
      x:=sqrt(6*s1/s2);
      writeln(x:0:6);
    end;
end.