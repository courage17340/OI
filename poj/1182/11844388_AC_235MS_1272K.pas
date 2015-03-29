var
  f,rank:array[1..50000] of longint;
  n,i,j,m,k,x,y,ans,t:longint;
function father(x:longint):longint;
begin
  if x=f[x] then exit(x);
  father:=father(f[x]);
  rank[x]:=(rank[x]+rank[f[x]]) mod 3;
  f[x]:=father;
end;
begin
  fillchar(rank,sizeof(rank),0);
  readln(n,m);
  for i:=1 to n do f[i]:=i;
  ans:=0;
  for i:=1 to m do
    begin
      readln(k,x,y);
      if (x>n)or(y>n) then
        begin
          inc(ans);
          continue;
        end;
      if k=1 then
        begin
          if father(x)=father(y) then
            if rank[x]<>rank[y] then
              begin
                inc(ans);
                continue;
              end;
          t:=father(x);
          f[t]:=father(y);
          rank[t]:=(rank[x]*2+rank[y]) mod 3;
        end;
      if k=2 then
        begin
          if father(x)=father(y) then
            if not((rank[x]-rank[y]=1)or(rank[x]-rank[y]=-2)) then
              begin
                inc(ans);
                continue;
              end;
          t:=father(x);
          f[t]:=father(y);
          rank[t]:=(rank[x]*2+rank[y]+1) mod 3; 
        end;
    end;
  writeln(ans);
end.