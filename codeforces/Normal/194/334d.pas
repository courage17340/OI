var
  a,b:array[1..1000] of longint;
  d,e:array[1..1000] of boolean;
  n,i,j,m,x,y,ans:longint;
begin
  readln(n,m);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  for i:=1 to m do
    begin
      readln(x,y);
      inc(a[x]);
      inc(b[y]);
    end;
  for i:=1 to n do d[i]:=a[i]=0;
  for i:=1 to n do e[i]:=b[i]=0;
  d[1]:=false;
  d[n]:=false;
  e[1]:=false;
  e[n]:=false;
  ans:=0;
  for i:=2 to n div 2 do
    begin
      x:=ord(d[i])+ord(d[n+1-i])+ord(e[i])+ord(e[n+1-i]);
      inc(ans,x);
    end;
  x:=(n+1) shr 1;
  if odd(n) and (d[x] or e[x]) then inc(ans);
  writeln(ans);
end.