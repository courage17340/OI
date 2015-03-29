{poj1703}
var
  f,rank:array[1..100000] of longint;
  n,m,i,j,k,r,x,y,t:longint;
  ch:char;
function father(x:longint):longint;
begin
  if f[x]=x then exit(x);
  father:=father(f[x]);
  rank[x]:=rank[x] xor rank[f[x]];
  f[x]:=father;
end;
begin
  readln(k);
  for r:=1 to k do
    begin
      readln(n,m);
      fillchar(rank,sizeof(rank),0);
      for i:=1 to n do f[i]:=i;
      for i:=1 to m do
        begin
          read(ch);
          readln(x,y);
          if ch='A' then
            begin
              if father(x)<>father(y) then writeln('Not sure yet.')
                else
                  if rank[x]<>rank[y] then writeln('In different gangs.')
                    else writeln('In the same gang.');
            end;
          if ch='D' then
            begin
              t:=father(x);
              f[t]:=father(y);
              rank[t]:=rank[x] xor rank[y] xor 1;
            end;
        end;
    end;
end.