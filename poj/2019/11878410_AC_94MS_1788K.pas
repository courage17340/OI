var
  a,b,d,f:array[1..250,1..250] of longint;
  v:array[1..250,1..250] of boolean;
  c:array[1..250] of longint;
  n,m,i,j,p,q,x,y,k:longint;
begin
  readln(n,k,m);
  for i:=1 to n do
    for j:=1 to n do read(a[i,j]);
  for i:=1 to n do
    begin
      p:=1;
      q:=1;
      c[p]:=1;
      for j:=2 to k do
        begin
          while (q>=p)and(a[i,c[q]]<=a[i,j]) do dec(q);
          inc(q);
          c[q]:=j;
        end;
      b[i,1]:=a[i,c[1]];
      for j:=k+1 to n do
        begin
          while (q>=p)and(a[i,c[q]]<=a[i,j]) do dec(q);
          inc(q);
          c[q]:=j;
          while c[p]<=j-k do inc(p);
          b[i,j-k+1]:=a[i,c[p]];
        end;
    end;
  for i:=1 to n do
    begin
      p:=1;
      q:=1;
      c[p]:=1;
      for j:=2 to k do
        begin
          while (q>=p)and(a[i,c[q]]>=a[i,j]) do dec(q);
          inc(q);
          c[q]:=j;
        end;
      d[i,1]:=a[i,c[1]];
      for j:=k+1 to n do
        begin
          while (q>=p)and(a[i,c[q]]>=a[i,j]) do dec(q);
          inc(q);
          c[q]:=j;
          while c[p]<=j-k do inc(p);
          d[i,j-k+1]:=a[i,c[p]];
        end;
    end;
  fillchar(f,sizeof(f),0);
  fillchar(v,sizeof(v),0);
  for i:=1 to m do
    begin
      readln(x,y);
      if v[x,y] then
        begin
          writeln(f[x,y]);
          continue;
        end;
      p:=b[x,y];
      q:=d[x,y];
      for j:=x+1 to x+k-1 do
        if p<b[j,y] then p:=b[j,y];
      for j:=x+1 to x+k-1 do
        if q>d[j,y] then q:=d[j,y];
      f[x,y]:=p-q;
      writeln(p-q);
      v[x,y]:=true;
    end;
end.